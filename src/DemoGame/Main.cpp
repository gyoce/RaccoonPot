#define SDL_MAIN_HANDLED
#include <iostream>
#include <Game.hpp>

int main() {
    std::cout << "Hello World!\n";
    Game game{};
    game.Init();
    return game.Run();
}