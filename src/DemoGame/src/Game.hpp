#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>

#include <Core/Managers/SceneManager.hpp>

class Game {
public:
    ~Game();

    void Init();
    int Run() const;

private:
    bool initUI();
    bool initGameEngine();

    bool initSDL();
    bool initWindow();
    bool initRenderer();

    bool initScenes();

    bool init = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::unique_ptr<SceneManager> sceneManager = nullptr;
};

#endif // GAME_HPP