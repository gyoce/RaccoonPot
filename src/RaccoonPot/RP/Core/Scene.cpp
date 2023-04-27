#include "RP/Core/Scene.hpp"

#include "RP/Logs/Log.hpp"
#include "RP/Core/Managers/EventManager.hpp"
#include "RP/Core/Managers/GuiManager.hpp"

using namespace RP;

Scene::Scene() {
    eventManager = std::make_shared<EventManager>();
    eventManager->Bind<void()>(SDL_QUIT, [this] { run = false; action = -1; });
    eventManager->Bind<void(int, int)>(SDL_MOUSEBUTTONDOWN, [](const int x, const int y) { Log("Click @[%d, %d]", x, y); });

    guiManager = std::make_shared<GuiManager>(1280, 720);
    guiManager->RegisterEventManager(eventManager);
    guiManager->RegisterClickEvent(SDL_MOUSEBUTTONDOWN);
}

void Scene::SetRenderer(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

int Scene::Loop() {
    run = true;
    double deltaTime = 0;
    while (run) {
        const std::uint64_t startFrame = SDL_GetPerformanceCounter();
        SDL_RenderClear(renderer);
        Event();
        Update(deltaTime);
        Draw();
        SDL_RenderPresent(renderer);
        const std::uint64_t endFrame = SDL_GetPerformanceCounter();
        deltaTime = static_cast<double>(endFrame - startFrame) / static_cast<double>(SDL_GetPerformanceFrequency());
    }
    return action;
}

void Scene::Event() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            eventManager->Dispatch<void()>(SDL_QUIT);
            break;
        case SDL_MOUSEBUTTONDOWN:
            eventManager->Dispatch<void(int, int)>(SDL_MOUSEBUTTONDOWN, event.motion.x, event.motion.y);
            break;
        }
    }
}

void Scene::Update(const double dt) {
    
}

void Scene::Draw() {
    guiManager->Render(renderer);
}