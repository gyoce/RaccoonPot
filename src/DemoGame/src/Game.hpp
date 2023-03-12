#ifndef GAME_HPP
#define GAME_HPP

#include <SDL3/SDL.h>

class Game {
public:
    Game();
    ~Game();
    int Run();

private:
    SDL_Window* window = nullptr;
};

#endif // GAME_HPP