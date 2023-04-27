#define SDL_MAIN_HANDLED

#include "DemoGame.hpp"

int main() {
    DemoGame game{};
    game.Init();
    return game.Run();
}