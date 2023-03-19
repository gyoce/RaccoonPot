#include "Game.hpp"

#include <Logs/Log.hpp>

Game::Game() {

}

void Game::Init() {
    init = initSDL();
}

Game::~Game() {
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
}

int Game::Run() {
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