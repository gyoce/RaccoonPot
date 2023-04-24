#include "MenuScene.hpp"

#include "../Gui/GuiButtonTexture.hpp"
#include "../Utils.hpp"

MenuScene::MenuScene(SDL_Renderer* renderer, SDL_Texture* spriteSheet, const std::shared_ptr<SdlGuiRenderSystem>& renderSystem)
    : Scene(renderer, spriteSheet, renderSystem) {  }

void MenuScene::Init() {
    initGui();
}

void MenuScene::initGui() {
    const std::shared_ptr<GuiButtonTexture> button = guiManager->CreateWidget<GuiButtonTexture>([this] { run = false; action = SaGame; });
    button->Position.x = 10; button->Position.y = 10; button->Width = 200; button->Height = 100;
    if (this->spriteSheet) {
        button->Texture = Utils::ExtractTextureFromSource({ 0, 0, 192, 64 }, this->renderer, this->spriteSheet);
    }
}