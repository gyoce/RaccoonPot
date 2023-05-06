#define SDL_MAIN_HANDLED

#include <RP/RP.hpp>

const std::vector<std::pair<std::string, SDL_Rect>> SpriteSheetInfos{
    { "ButtonMenu", { 0, 0, 192, 64 }},
    { "ButtonGame", { 0, 64, 192, 64 }}
};

enum SceneAction {
    SaQuit,
    SaMenu,
    SaGame
};

class MenuScene final: public RP::Scene {
public:
    RP_SCENE_CONSTRUCTOR(MenuScene) {
        const RP::GuiButtonPtr button = guiManager->CreateWidget<RP::GuiButton>([this] { run = false; action = SaGame; });
        button->SetSize(100, 100);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }
};

class GameScene final: public RP::Scene {
public:
    RP_SCENE_CONSTRUCTOR(GameScene) {
        const RP::GuiButtonPtr button = guiManager->CreateWidget<RP::GuiButton>([this] { run = false; action = SaMenu; });
        button->SetSize(200, 200);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }
};

class DemoGame final: public RP::Game {
public:
    explicit DemoGame(const RP::GameOptions& options): Game(options) {
        sceneManager->SetBaseAction(SaMenu);
        sceneManager->RegisterScene<MenuScene>(SaMenu);
        sceneManager->RegisterScene<GameScene>(SaGame);
        resourceManager->LoadSpriteSheet("res/SpriteSheet.png", "MainSpriteSheet", SpriteSheetInfos);
    }
};

int main() {
    const RP::GameOptions options{
        .VSync = true,
        .Width = 1920,
        .Height = 1080,
        .Title = "DemoGame"
    };
    const DemoGame game{options};
    return game.Run();
}