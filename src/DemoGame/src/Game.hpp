#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>

class Game {
public:
    Game() = default;
    ~Game();

    void Init();
    int Run() const;

private:
    bool initSDL();
    bool initWindow();
    bool initRenderer();

    bool init = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif // GAME_HPP