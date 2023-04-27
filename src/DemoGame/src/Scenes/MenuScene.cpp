#include "MenuScene.hpp"

#include "SceneAction.hpp"

void MenuScene::Init() {
    initGui();
}

void MenuScene::initGui() {
    const RP::GuiButtonPtr button = guiManager->CreateWidget<RP::GuiButton>([this] { run = false; action = SaGame; });
    button->Position.x = 10; button->Position.y = 10;
    button->Width = 100; button->Height = 100;
}