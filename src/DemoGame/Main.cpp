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
    MenuScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet)
        : Scene(renderer), spriteSheet(std::move(spriteSheet)) {
        std::function callback = [this] { run = false; action = SaGame; };
        const RP::GuiButtonTexturePtr button = guiManager->CreateWidget<RP::GuiButtonTexture>(callback, this->spriteSheet->GetTextureByName("ButtonMenu"));
        button->SetSize(128, 64);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }

private:
    RP::SpriteSheetPtr spriteSheet = nullptr;
};

class GameScene final: public RP::Scene {
public:
    GameScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet)
        : Scene(renderer), spriteSheet(std::move(spriteSheet)) {
        std::function callback = [this] { run = false; action = SaMenu; };
        const RP::GuiButtonTexturePtr button = guiManager->CreateWidget<RP::GuiButtonTexture>(callback, this->spriteSheet->GetTextureByName("ButtonGame"));
        button->SetSize(256, 128);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }

private:
    RP::SpriteSheetPtr spriteSheet = nullptr;
};

class DemoGame final: public RP::Game {
public:
    explicit DemoGame(const RP::GameOptions& options): Game(options) {
        RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet("res/SpriteSheet.png", "MainSpriteSheet", SpriteSheetInfos);
        sceneManager->SetBaseAction(SaMenu);
        sceneManager->RegisterScene<MenuScene>(SaMenu, spriteSheet);
        sceneManager->RegisterScene<GameScene>(SaGame, spriteSheet);
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