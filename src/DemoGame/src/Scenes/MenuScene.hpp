#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

class MenuScene final : public RP::Scene {
public:
    explicit MenuScene(SDL_Renderer* renderer);
    void Init();
    int Loop() override;

private:
    void event() const;
    void draw() const;

    void initEvents();
    void initGui();

    bool run = false;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* spriteSheet = nullptr;
    std::shared_ptr<RP::EventManager> eventManager = nullptr;
    std::shared_ptr<RP::GuiManager> guiManager = nullptr;
};

#endif // MENU_SCENE_HPP