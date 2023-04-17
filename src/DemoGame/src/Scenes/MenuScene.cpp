#include "MenuScene.hpp"

#include <SDL2/SDL.h>
#include <RP/Logs/Log.hpp>

#include "SceneAction.hpp"
#include "../Events.hpp"

void MenuScene::Init(SDL_Renderer* renderer) {
    this->renderer = renderer;
    eventManager = std::make_shared<RP::EventManager>();
    eventManager->Bind<void()>(EQuit, [this] { quitMenu(); });
    eventManager->Bind<void(int, int)>(EClick, [](int x, int y) { click(x, y); });
}

int MenuScene::Loop() {
    run = true;
    while (run) {
        SDL_RenderClear(renderer);

        event();

        SDL_RenderPresent(renderer);
    }
    return SaQuit;
}

void MenuScene::event() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            eventManager->Dispatch<void()>(EQuit);
            break;
        case SDL_MOUSEBUTTONDOWN:
            eventManager->Dispatch<void(int, int)>(EClick, event.motion.x, event.motion.y);
            break;
        }
    }
}

void MenuScene::quitMenu() {
    run = false;
}

void MenuScene::click(int x, int y) {
    RP::Log("Click @[%d, %d]", x, y);
}
