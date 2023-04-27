#include "DemoGame.hpp"

#include "Scenes/SceneAction.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/GameScene.hpp"

void DemoGame::Init() const {
    sceneManager->SetBaseAction(SaMenu);
    sceneManager->RegisterScene<MenuScene>(SaMenu)->Init();
    sceneManager->RegisterScene<GameScene>(SaGame)->Init();
}
