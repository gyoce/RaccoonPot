#include "Game.hpp"

#include <RP/Logs/Log.hpp>

#include "Scenes/MenuScene.hpp"
#include "Scenes/SceneAction.hpp"

Game::~Game() {
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
    SDL_Quit();
}

void Game::Init() {
    init = initUi() && initGameEngine();
}

int Game::Run() const {
    return init ? sceneManager->Loop() : -1;
}

bool Game::initUi() {
    return initSdl() && initWindow() && initRenderer();
}

bool Game::initGameEngine() {
    return initScenes();
}

bool Game::initSdl() {
    RP::Log("Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        RP::LogError("Error while initializing SDL %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initWindow() {
    RP::Log("Initializing Window");
    window = SDL_CreateWindow("DemoGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    if (window == nullptr) {
        RP::LogError("Error while initializing Window %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initRenderer() {
    RP::Log("Initializing Renderer");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        RP::LogError("Error while initializing Renderer %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initScenes() {
    sceneManager = std::make_unique<RP::SceneManager>(SaMenu);
    const std::shared_ptr<MenuScene> menuScene = sceneManager->RegisterScene<MenuScene>(SaMenu);
    menuScene->Init(renderer);
    return true;
}