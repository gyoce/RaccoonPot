#include "Game.hpp"

#include <Logs/Log.hpp>

Game::Game() {

}

void Game::Init() {
    init = initSDL() && initWindow() && initRenderer();
}

Game::~Game() {
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
    SDL_Quit();
}

int Game::Run() const {
    if (!init) { return -1; }
    bool run = true;
    while (run) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    run = false;
                    break;
            }
        }
    }
    
    return 0;
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
    window = SDL_CreateWindow("DemoGame", 1280, 720, 0);
    if (window == nullptr) {
        ECSGameEngine::Log::LogError("Error while initializing Window %s", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initRenderer() {
    ECSGameEngine::Log::Log("Initializing Renderer");
    renderer = SDL_CreateRenderer(window, nullptr, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        ECSGameEngine::Log::LogError("Error while initializing Renderer %s", SDL_GetError());
        return false;
    }
    return true;
}