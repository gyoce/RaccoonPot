#include "GameScene.hpp"

#include "../Gui/GuiButtonTexture.hpp"
#include "../Utils.hpp"

GameScene::GameScene(SDL_Renderer* renderer, SDL_Texture* spriteSheet)
    : Scene(renderer, spriteSheet) {  }

void GameScene::Init() {
    initGui();
}

void GameScene::initGui() {
    const std::shared_ptr<GuiButtonTexture> button = guiManager->CreateWidget<GuiButtonTexture>([this] { run = false; action = SaMenu; });
    button->x = 100; button->y = 100; button->Width = 200; button->Height = 100;
    if (this->spriteSheet) {
        button->Texture = Utils::ExtractTextureFromSource({ 0, 64, 192, 64 }, this->renderer, this->spriteSheet);
    }
}
