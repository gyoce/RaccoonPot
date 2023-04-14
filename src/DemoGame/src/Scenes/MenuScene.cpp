#include "MenuScene.hpp"

#include <SDL2/SDL.h>

#include <Scenes/SceneAction.hpp>

int MenuScene::Loop() {
    bool run = true;
    while (run) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                run = false;
                break;
            }
        }
    }
    return SA_Quit;
}
