#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <SDL2/SDL.h>

#include "Scene.hpp"

class GameScene final : public Scene {
public:
    explicit GameScene(SDL_Renderer* renderer, SDL_Texture* spriteSheet, const std::shared_ptr<SdlGuiRenderSystem>& renderSystem);
    void Init();

private:
    void initGui();
};

#endif // GAME_SCENE_HPP