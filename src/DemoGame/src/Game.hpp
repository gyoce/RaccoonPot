#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

class Game {
public:
    ~Game();

    void Init();
    int Run() const;

private:
    bool initUi();
    bool initGameEngine();

    static bool initSdl();
    bool initWindow();
    bool initRenderer();

    bool initScenes();

    bool init = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::unique_ptr<RP::SceneManager> sceneManager = nullptr;
};

#endif // GAME_HPP