#include "MenuScene.hpp"

#include <SDL2/SDL_image.h>

#include "SceneAction.hpp"
#include "../Events.hpp"
#include "../Gui/GuiButtonTexture.hpp"
#include "../Utils.hpp"

void MenuScene::Init(SDL_Renderer* renderer) {
    this->renderer = renderer;

    if (SDL_Surface* surface = IMG_Load("res/SpriteSheet.png"); surface == nullptr) {
        RP::LogError("Could not load res/SpriteSheet.png");
    } else {
        this->spriteSheet = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    eventManager = std::make_shared<RP::EventManager>();
    eventManager->Bind<void()>(EQuit, [this] { quitMenu(); });
    eventManager->Bind<void(int, int)>(EClick, [](const int x, const int y) { click(x, y); });

    guiManager = std::make_shared<RP::GuiManager>();
    guiManager->RegisterEventManager(eventManager);
    guiManager->RegisterRenderFunctionForWidget<GuiButtonTexture>([this](const std::shared_ptr<GuiButtonTexture>& button) {
        const SDL_Rect rect = { button->x, button->y, button->Width, button->Height };
        SDL_RenderCopy(this->renderer, button->Texture, nullptr, &rect);
    });
    const std::shared_ptr<GuiButtonTexture> button = guiManager->CreateWidget<GuiButtonTexture>();
    button->x = 10; button->y = 10; button->Width = 200; button->Height = 100;
    if (this->spriteSheet) {
        button->Texture = Utils::ExtractTextureFromSource({ 0, 0, 192, 64 }, this->renderer, this->spriteSheet);
    }
}

int MenuScene::Loop() {
    run = true;
    while (run) {
        SDL_RenderClear(renderer);

        event();
        draw();

        SDL_RenderPresent(renderer);
    }
    return SaQuit;
}

void MenuScene::event() const {
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

void MenuScene::draw() const {
    guiManager->Render();
}

void MenuScene::quitMenu() {
    run = false;
}

void MenuScene::click(const int x, const int y) {
    RP::Log("Click @[%d, %d]", x, y);
}