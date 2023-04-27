#include "RP/Game.hpp"

#include "RP/Logs/Log.hpp"
#include "RP/Core/Managers/SceneManager.hpp"

using namespace RP;

Game::Game() {
    init();
    sceneManager = std::make_shared<SceneManager>(renderer);
}

Game::~Game() {
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
    SDL_Quit();
}

void Game::init() {
    isInitialized = initSdl() && initWindow() && initRenderer();
}

int Game::Run() const {
    return isInitialized ? sceneManager->Loop() : -1;
}

bool Game::initSdl() {
    Log("Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        LogError("Error while initializing SDL : %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initWindow() {
    Log("Initializing Window");
    window = SDL_CreateWindow("DemoGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        LogError("Error while initializing Window : %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initRenderer() {
    Log("Initializing Renderer");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        LogError("Error while initializing Renderer : %s", SDL_GetError());
        return false;
    }
    return true;
}