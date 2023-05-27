#define SDL_MAIN_HANDLED

#include "Main.hpp"
#include "Sort.hpp"

class MenuScene final: public RP::Scene {
public:
    MenuScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet, RP::FontPtr font)
        : Scene(renderer), spriteSheet(std::move(spriteSheet)), font(std::move(font)) {
        initButtons();
    }

private:
    void initButtons() {
        std::function callback = [this] { run = false; action = SaGame; };
        const RP::GuiButtonTextureTextPtr button = guiManager->CreateWidget<RP::GuiButtonTextureText>(
            callback, this->spriteSheet->GetTextureByName("ButtonSort"), "Sort", font);
        button->SetSize(128, 64);
        button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        guiManager->AddToMainPanel(button);
    }
    
    RP::SpriteSheetPtr spriteSheet = nullptr;
    RP::FontPtr font = nullptr;
};

class DemoGame final: public RP::Game {
public:
    explicit DemoGame(const RP::GameOptions& options): Game(options) {
        RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet("res/SpriteSheet.png", "MainSpriteSheet", SpriteSheetInfos);
        RP::FontPtr font = resourceManager->LoadFont("res/Font.ttf", "MainFont", 14);
        sceneManager->SetBaseAction(SaMenu);
        sceneManager->RegisterScene<MenuScene>(SaMenu, spriteSheet, font);
        sceneManager->RegisterScene<SortingAlgorithmsScene>(SaGame, spriteSheet, font);
    }
};

int main() {
    const DemoGame game{Options};
    return game.Run();
}