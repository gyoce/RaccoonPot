#include "MenuScene.hpp"

#include "../Gui/GuiButtonTexture.hpp"
#include "../Utils.hpp"

MenuScene::MenuScene(SDL_Renderer* renderer, SDL_Texture* spriteSheet)
    : Scene(renderer, spriteSheet) {  }

void MenuScene::Init() {
    initGui();
}

void MenuScene::initGui() {
    const std::shared_ptr<GuiButtonTexture> button = guiManager->CreateWidget<GuiButtonTexture>([this] { run = false; action = SaGame; });
    button->x = 10; button->y = 10; button->Width = 200; button->Height = 100;
    if (this->spriteSheet) {
        button->Texture = Utils::ExtractTextureFromSource({ 0, 0, 192, 64 }, this->renderer, this->spriteSheet);
    }
}