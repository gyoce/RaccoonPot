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
    MenuScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet, RP::FontPtr font)
        : Scene(renderer), spriteSheet(std::move(spriteSheet)), font(std::move(font)) {
        initButtons();
        //initTexts();
    }

private:
    void initButtons() {
        std::function callback = [this] { run = false; action = SaGame; };
        const RP::GuiButtonTextureTextPtr button = guiManager->CreateWidget<RP::GuiButtonTextureText>(
            callback, this->spriteSheet->GetTextureByName("ButtonMenu"), "Menu", font);
        button->SetSize(128, 64);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }

    void initTexts() {
        const RP::GuiTextPtr text = guiManager->CreateWidget<RP::GuiText>("MyMenu", font);
        text->SetSize(128, 64);
        text->SetPosition(700, 10);
        guiManager->AddToMainPanel(text);
    }

    RP::SpriteSheetPtr spriteSheet = nullptr;
    RP::FontPtr font = nullptr;
};

class GameScene final: public RP::Scene {
public:
    GameScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet, RP::FontPtr font)
        : Scene(renderer), spriteSheet(std::move(spriteSheet)), font(std::move(font)) {
        std::function callback = [this] { run = false; action = SaMenu; };
        const RP::GuiButtonTexturePtr button = guiManager->CreateWidget<RP::GuiButtonTexture>(callback, this->spriteSheet->GetTextureByName("ButtonGame"));
        button->SetSize(256, 128);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }

private:
    RP::SpriteSheetPtr spriteSheet = nullptr;
    RP::FontPtr font = nullptr;
};

class DemoGame final: public RP::Game {
public:
    explicit DemoGame(const RP::GameOptions& options): Game(options) {
        RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet("res/SpriteSheet.png", "MainSpriteSheet", SpriteSheetInfos);
        RP::FontPtr font = resourceManager->LoadFont("res/Font.ttf", "MainFont", 18);
        sceneManager->SetBaseAction(SaMenu);
        sceneManager->RegisterScene<MenuScene>(SaMenu, spriteSheet, font);
        sceneManager->RegisterScene<GameScene>(SaGame, spriteSheet, font);
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