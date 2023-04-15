#include "MenuScene.hpp"

#include <SDL2/SDL.h>
#include <RP/Core/Components/Transform2.hpp>

#include "SceneAction.hpp"
#include "../Systems/RenderSystem.hpp"
#include "../Entities/Button.hpp"


void MenuScene::Init(SDL_Renderer* renderer) {
    this->renderer = renderer;
    coordinator->RegisterComponent<RP::Transform2>();
    renderSystem = coordinator->RegisterSystem<RenderSystem>();
    coordinator->SetSystemSignature<RenderSystem>(RenderSystem::GetSignature(coordinator));
    Button::CreateButton(coordinator);
}

int MenuScene::Loop() {
    bool run = true;
    float dt = 0.0f;
    while (run) {
        SDL_RenderClear(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                run = false;
                break;
            }
        }

        renderSystem->Update(dt, coordinator, renderer);

        SDL_RenderPresent(renderer);
    }
    return SA_Quit;
}
