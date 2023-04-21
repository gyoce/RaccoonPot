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

    static bool initSdl();
    bool initWindow();
    bool initRenderer();

    void initScenes();
    bool initSpriteSheet();

    bool init = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* spriteSheet = nullptr;
    std::unique_ptr<RP::SceneManager> sceneManager = nullptr;
};

#endif // GAME_HPP