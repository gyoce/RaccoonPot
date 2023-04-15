#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <RP/Core/Scene.hpp>

#include "../Systems/RenderSystem.hpp"

class MenuScene : public RP::Scene {
public:
    SCENE_CONSTRUCTOR(MenuScene)
    int Loop() override;
    void Init(SDL_Renderer* renderer);

private:
    std::shared_ptr<RenderSystem> renderSystem;
    SDL_Renderer* renderer = nullptr;
};

#endif // MENU_SCENE_HPP