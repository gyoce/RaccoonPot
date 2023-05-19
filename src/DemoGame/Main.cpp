#define SDL_MAIN_HANDLED

#include <RP/RP.hpp>
#include "SortGui.hpp"

const std::vector<std::pair<std::string, SDL_Rect>> SpriteSheetInfos{
    { "ButtonMenu", { 0, 0, 192, 64 }},
    { "ButtonGame", { 0, 64, 192, 64 }}
};

const RP::GameOptions Options{
    .VSync = true,
    .Title = "DemoGame",
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

    RP::SpriteSheetPtr spriteSheet = nullptr;
    RP::FontPtr font = nullptr;
};

class SortingAlgorithmsScene final: public RP::Scene {
public:
    SortingAlgorithmsScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet, RP::FontPtr font)
        : Scene(renderer), spriteSheet(std::move(spriteSheet)), font(std::move(font)) {
        initPanels();
        initButtons();
        sortGui = std::make_shared<SortGui>(renderer, 0, 0, Options.Width, Options.Height - bottomPanel->GetHeight());
        eventManager->Bind<void()>(SDL_QUIT, [this] { sortGui->StopSort(); });
    }

private:
    void initPanels() {
        bottomPanel = guiManager->CreateWidget<RP::GuiPanel>();
        bottomPanel->SetBackgroundColor({ 249, 109, 109, 255 });
        bottomPanel->SetSize(Options.Width, 200);
        bottomPanel->SetVerticalAnchor(RP::VerticalAnchor::Bottom);
        guiManager->AddToMainPanel(bottomPanel);

        const RP::GuiPanelPtr panelStats = guiManager->CreateWidget<RP::GuiPanel>();
        panelStats->SetBackgroundColor({ 184, 77, 105, 255 });
        panelStats->SetSize(300, 200);
        panelStats->SetAnchor(RP::HorizontalAnchor::Right, RP::VerticalAnchor::Center);
        bottomPanel->AddChild(panelStats);

        panelButtons = guiManager->CreateWidget<RP::GuiPanel>();
        panelButtons->SetPaddingBetweenChildren(20);
        panelButtons->SetAlignItems(RP::AlignItems::Row);
        panelButtons->SetSize(bottomPanel->GetWidth() - panelStats->GetWidth(), 150);
        panelButtons->SetAnchor(RP::HorizontalAnchor::Left, RP::VerticalAnchor::Center);
        bottomPanel->AddChild(panelButtons);
    }

    void initButtons() const {
        std::function callbackInsertionSort = [this] { sortGui->SetUp(SortingAlgorithm::InsertionSort); };
        const RP::GuiButtonTextPtr btnInsertionSort = guiManager->CreateWidget<RP::GuiButtonText>(callbackInsertionSort, "Insertion Sort", font);
        btnInsertionSort->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        btnInsertionSort->SetSize(225, 50);
        btnInsertionSort->SetBackgroundColor({ 169, 215, 246, 255 });
        btnInsertionSort->SetPadding(10);
        panelButtons->AddChild(btnInsertionSort);

        std::function callbackBubbleSort = [this] { sortGui->SetUp(SortingAlgorithm::BubbleSort); };
        const RP::GuiButtonTextPtr btnBubbleSort = guiManager->CreateWidget<RP::GuiButtonText>(callbackBubbleSort, "Bubble Sort", font);
        btnBubbleSort->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        btnBubbleSort->SetSize(225, 50);
        btnBubbleSort->SetBackgroundColor({ 169, 215, 246, 255 });
        btnBubbleSort->SetPadding(10);
        panelButtons->AddChild(btnBubbleSort);

        std::function callbackQuickSort = [this] { sortGui->SetUp(SortingAlgorithm::QuickSort); };
        const RP::GuiButtonTextPtr btnQuickSort = guiManager->CreateWidget<RP::GuiButtonText>(callbackQuickSort, "Quick Sort", font);
        btnQuickSort->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
        btnQuickSort->SetSize(225, 50);
        btnQuickSort->SetBackgroundColor({ 169, 215, 246, 255 });
        btnQuickSort->SetPadding(10);
        panelButtons->AddChild(btnQuickSort);
    }

    void Draw() override {
        Scene::Draw();
        sortGui->Draw();
    }

    RP::SpriteSheetPtr spriteSheet = nullptr;
    RP::FontPtr font = nullptr;
    RP::GuiPanelPtr panelButtons = nullptr;
    RP::GuiPanelPtr bottomPanel = nullptr;
    std::shared_ptr<SortGui> sortGui = nullptr;
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