#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <SDL2/SDL.h>
#include <RP/Core/Scene.hpp>
#include <RP/Core/Managers/EventManager.hpp>

class MenuScene : public RP::Scene {
public:
    RP_SCENE_CONSTRUCTOR(MenuScene)
    int Loop() override;
    void Init(SDL_Renderer* renderer);

private:
    void quitMenu();

    bool run = false;
    SDL_Renderer* renderer = nullptr;
    std::shared_ptr<RP::EventManager> eventManager = nullptr;
};

#endif // MENU_SCENE_HPP