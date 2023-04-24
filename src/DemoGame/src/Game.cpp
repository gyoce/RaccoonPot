#include "Game.hpp"

#include <SDL2/SDL_image.h>

#include "Scenes/MenuScene.hpp"
#include "Scenes/GameScene.hpp"
#include "Scenes/SceneAction.hpp"

Game::~Game() {
    if (spriteSheet != nullptr) { SDL_DestroyTexture(spriteSheet); }
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
    SDL_Quit();
}

void Game::Init() {
    init = initUi() && initSpriteSheet();
    renderSystem = std::make_shared<SdlGuiRenderSystem>(renderer);
    initScenes();
}

int Game::Run() const {
    return init ? sceneManager->Loop() : -1;
}

bool Game::initUi() {
    return initSdl() && initWindow() && initRenderer();
}

bool Game::initSdl() {
    RP::Log("Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        RP::LogError("Error while initializing SDL : %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initWindow() {
    RP::Log("Initializing Window");
    window = SDL_CreateWindow("DemoGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        RP::LogError("Error while initializing Window : %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initRenderer() {
    RP::Log("Initializing Renderer");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        RP::LogError("Error while initializing Renderer : %s", SDL_GetError());
        return false;
    }
    return true;
}

void Game::initScenes() {
    sceneManager = std::make_unique<RP::SceneManager>(SaMenu);
    sceneManager->RegisterScene<MenuScene>(SaMenu, renderer, spriteSheet, renderSystem)->Init();
    sceneManager->RegisterScene<GameScene>(SaGame, renderer, spriteSheet, renderSystem)->Init();
}

bool Game::initSpriteSheet() {
    SDL_Surface* surface = IMG_Load("res/SpriteSheet.png");
    if (surface == nullptr) {
        RP::LogError("Error while loading spritesheet : %s", SDL_GetError());
        return false;
    }

    spriteSheet = SDL_CreateTextureFromSurface(renderer, surface);
    if (spriteSheet == nullptr) {
        RP::LogError("Error while creating texture from surfcace : %s", SDL_GetError());
        return false;
    }

    return true;
}
