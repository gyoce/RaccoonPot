#include "RP/Game.hpp"

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "RP/Logs/Log.hpp"
#include "RP/Core/Managers/ResourceManager.hpp"
#include "RP/Core/Managers/SceneManager.hpp"

namespace RP
{

Game::Game(GameOptions options)
    : options(std::move(options)) {
    init();
    sceneManager = std::make_shared<SceneManager>(renderer);
    resourceManager = std::make_shared<ResourceManager>(renderer);
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::init() {
    isInitialized = initSdl() && initTtf() && initSdlImage() && initWindow() && initRenderer();
}

int Game::Run() const {
    return isInitialized ? sceneManager->Loop() : -1;
}

bool Game::initSdl() {
    Log("Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        LogError("Error while initializing SDL : {}", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initTtf() {
    Log("Initializing TTF");
    if (TTF_Init() < 0) {
        LogError("Error while initializing TTF : {}", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initSdlImage() {
    Log("Initializing SDL Image");
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        LogError("Error while initializing SDL Image : {}", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initWindow() {
    Log("Initializing Window");
    window = SDL_CreateWindow(options.Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, options.Width, options.Height, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        LogError("Error while initializing Window : {}", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::initRenderer() {
    Log("Initializing Renderer");
    renderer = SDL_CreateRenderer(window, -1, getRendererFlags());
    if (renderer == nullptr) {
        LogError("Error while initializing Renderer : {}", SDL_GetError());
        return false;
    }
    return true;
}

int Game::getRendererFlags() const {
    int flags = SDL_RENDERER_ACCELERATED;
    if (options.VSync) {
        flags |= SDL_RENDERER_PRESENTVSYNC;
    }
    return flags;
}

} // namespace RP