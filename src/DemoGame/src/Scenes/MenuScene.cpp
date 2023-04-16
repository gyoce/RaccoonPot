#include "MenuScene.hpp"

#include <SDL2/SDL.h>

#include "SceneAction.hpp"
#include "../Events.hpp"

void MenuScene::Init(SDL_Renderer* renderer) {
    this->renderer = renderer;
    eventManager = std::make_shared<RP::EventManager>();
    eventManager->Bind(E_Quit, [this] { quitMenu(); });
}

int MenuScene::Loop() {
    run = true;
    while (run) {
        SDL_RenderClear(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                eventManager->Dispatch(E_Quit);
                break;
            }
        }

        SDL_RenderPresent(renderer);
    }
    return SA_Quit;
}

void MenuScene::quitMenu() {
    run = false;
}
