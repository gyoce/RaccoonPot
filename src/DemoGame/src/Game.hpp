#ifndef GAME_HPP
#define GAME_HPP

#include <SDL3/SDL.h>

class Game {
public:
    Game();
    ~Game();

    void Init();
    int Run();

private:
    bool initSDL();

    bool init = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif // GAME_HPP