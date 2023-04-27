#define SDL_MAIN_HANDLED

#include <RP/RP.hpp>

enum SceneAction {
    SaQuit,
    SaMenu,
    SaGame
};

class MenuScene final: public RP::Scene {
public:
    MenuScene() {
        const RP::GuiButtonPtr button = guiManager->CreateWidget<RP::GuiButton>([this] { run = false; action = SaGame; });
        button->SetPosition(10, 10); button->Width = 100; button->Height = 100;
    }
};

class GameScene final: public RP::Scene {
public:
    GameScene() {
        const RP::GuiButtonPtr button = guiManager->CreateWidget<RP::GuiButton>([this] { run = false; action = SaMenu; });
        button->SetPosition(200, 200); button->Width = 100; button->Height = 100;
    }
};

class DemoGame final: public RP::Game {
public:
    explicit DemoGame(const RP::GameOptions& options): Game(options) {
        sceneManager->SetBaseAction(SaMenu);
        sceneManager->RegisterScene<MenuScene>(SaMenu);
        sceneManager->RegisterScene<GameScene>(SaGame);
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