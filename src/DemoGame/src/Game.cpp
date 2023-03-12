#include "Game.hpp"

Game::Game() {

}

Game::~Game() {
    if (window != nullptr) { SDL_DestroyWindow(window); }
}

int Game::Run() {
    return 0;
}