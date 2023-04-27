#include "GameScene.hpp"

#include "SceneAction.hpp"

void GameScene::Init() {
    initGui();
}

void GameScene::initGui() {
    const RP::GuiButtonPtr button = guiManager->CreateWidget<RP::GuiButton>([this] { run = false; action = SaMenu; });
    button->Position.x = 200; button->Position.y = 200;
    button->Width = 100; button->Height = 100;
}