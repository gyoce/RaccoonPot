#include "Scene.hpp"

#include "../Events.hpp"
#include "../Gui/GuiButtonTexture.hpp"

Scene::Scene(SDL_Renderer* renderer, SDL_Texture* spriteSheet)
    : renderer(renderer), spriteSheet(spriteSheet) {
    eventManager = std::make_shared<RP::EventManager>();
    eventManager->Bind<void()>(EQuit, [this] { run = false; action = SaQuit; });
    guiManager = std::make_shared<RP::GuiManager>();
    guiManager->RegisterEventManager(eventManager);
    guiManager->RegisterClickEvent(EClick);
    guiManager->RegisterRenderFunctionForWidget<GuiButtonTexture>([this](const std::shared_ptr<GuiButtonTexture>& button) {
        const SDL_Rect rect = { button->x, button->y, button->Width, button->Height };
        SDL_RenderCopy(this->renderer, button->Texture, nullptr, &rect);
    });
}

int Scene::Loop() {
    run = true;
    while (run) {
        SDL_RenderClear(renderer);

        Event();
        Draw();

        SDL_RenderPresent(renderer);
    }
    return action;
}

void Scene::Event() {
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

void Scene::Draw() {
    guiManager->Render();
}
