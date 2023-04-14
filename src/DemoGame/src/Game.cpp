#include "Game.hpp"

#include <Logs/Log.hpp>

#include <Scenes/MenuScene.hpp>
#include <Scenes/SceneAction.hpp>

Game::~Game() {
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
    SDL_Quit();
}

void Game::Init() {
    init = initUI() && initGameEngine();
}

int Game::Run() const {
    return init ? sceneManager->Loop() : -1;
}

bool Game::initUI() {
    return initSDL() && initWindow() && initRenderer();
}

bool Game::initGameEngine() {
    return initScenes();
}

bool Game::initSDL() {
    ECSGameEngine::Log::Log("Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        ECSGameEngine::Log::LogError("Error while initializing SDL %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initWindow() {
    ECSGameEngine::Log::Log("Initializing Window");
    window = SDL_CreateWindow("DemoGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    if (window == nullptr) {
        ECSGameEngine::Log::LogError("Error while initializing Window %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initRenderer() {
    ECSGameEngine::Log::Log("Initializing Renderer");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        ECSGameEngine::Log::LogError("Error while initializing Renderer %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initScenes() {
    sceneManager = std::make_unique<SceneManager>(SceneAction::Menu);
    sceneManager->RegisterScene<MenuScene>(SceneAction::Menu);
    return true;
}