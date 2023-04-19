#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

class MenuScene : public RP::Scene {
public:
    RP_SCENE_CONSTRUCTOR(MenuScene)
    void Init(SDL_Renderer* renderer);
    int Loop() override;

private:
    void event() const;
    void draw() const;
    void quitMenu();
    static void click(int x, int y);

    bool run = false;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* spriteSheet = nullptr;
    std::shared_ptr<RP::EventManager> eventManager = nullptr;
    std::shared_ptr<RP::GuiManager> guiManager = nullptr;
};

#endif // MENU_SCENE_HPP