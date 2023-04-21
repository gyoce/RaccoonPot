#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <SDL2/SDL.h>

#include "Scene.hpp"

class MenuScene final : public Scene {
public:
    explicit MenuScene(SDL_Renderer* renderer, SDL_Texture* spriteSheet);
    void Init();

private:
    void initGui();
};

#endif // MENU_SCENE_HPP