#ifndef SCENE_HPP
#define SCENE_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

#include "SceneAction.hpp"

class Scene : public RP::Scene {
public:
    explicit Scene(SDL_Renderer* renderer, SDL_Texture* spriteSheet);

protected:
    int Loop() override;
    virtual void Event();
    virtual void Draw();


    bool run = false;
    SceneAction action{};
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* spriteSheet = nullptr;
    RP::EventManagerPtr eventManager = nullptr;
    RP::GuiManagerPtr guiManager = nullptr;
};

#endif // SCENE_HPP