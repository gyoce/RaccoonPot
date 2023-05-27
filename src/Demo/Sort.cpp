#include "Sort.hpp"

#include "Main.hpp"

#include <random>

constexpr int SizeOfEachValue = 10;
constexpr int PaddingBetweenValues = 5;
std::atomic delayInMs = { 100 };

// *************************************************
// -------------------------------------------------
//                    SORT GUI
// -------------------------------------------------
// *************************************************

SortGui::SortGui(SDL_Renderer* renderer, const int x, const int y, const  int width, const  int height)
    : renderer(renderer), workingRectangle(x, y, width, height) {
    numberOfValues = width / (SizeOfEachValue + PaddingBetweenValues);
}

void SortGui::Start(const SortingAlgorithm sortingAlgorithm) {
    this->actualAlgorithm = sortingAlgorithm;
    StopSort();
    generateRandomValues();
    forceStop = false;
    sortingThread = std::thread(&SortGui::startSort, this);
}

void SortGui::StopSort() {
    forceStop = true;
    if (sortingThread.joinable()) {
        sortingThread.join();
    }
}

void SortGui::Draw() const {
    if (values.empty()) { return; }
    SDL_Color color;
    SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
    drawValues();
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void SortGui::drawValues() const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < numberOfValues; i++) {
        const int value = values[i];
        const SDL_Rect rect{
            workingRectangle.x + PaddingBetweenValues + (SizeOfEachValue + PaddingBetweenValues) * i,
            workingRectangle.y + workingRectangle.h - value,
            SizeOfEachValue,
            value
        };
        SDL_RenderFillRect(renderer, &rect);
    }
}

void SortGui::startSort() {
    switch (actualAlgorithm) {
    case SortingAlgorithm::InsertionSort:
        InsertionSort(values, forceStop);
        break;
    case SortingAlgorithm::BubbleSort:
        BubbleSort(values, forceStop);
        break;
    case SortingAlgorithm::QuickSort:
        QuickSort(values, 0, numberOfValues - 1, forceStop);
        break;
    }
}

void SortGui::generateRandomValues() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution uni{ 1, workingRectangle.h - 5 };
    values.clear();
    for (int i = 0; i < numberOfValues; i++) {
        values.push_back(uni(rng));
    }
}

// *************************************************
// -------------------------------------------------
//           SORTING ALGORITHMS SCENE
// -------------------------------------------------
// *************************************************

SortingAlgorithmsScene::SortingAlgorithmsScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet, RP::FontPtr font)
    : Scene(renderer), spriteSheet(std::move(spriteSheet)), font(std::move(font)) {
    initPanels();
    initButtons();
    sortGui = std::make_shared<SortGui>(renderer, 0, 0, Options.Width, Options.Height - panelBottom->GetHeight());
    eventManager->Bind<void()>(SDL_QUIT, [this] { sortGui->StopSort(); });
}

void SortingAlgorithmsScene::initPanels() {
    panelBottom = guiManager->CreateWidget<RP::GuiPanel>();
    panelBottom->SetBackgroundColor({ 249, 109, 109, 255 });
    panelBottom->SetSize(Options.Width, 200);
    panelBottom->SetVerticalAnchor(RP::VerticalAnchor::Bottom);
    panelBottom->SetAlignItems(RP::AlignItems::Row);
    guiManager->AddToMainPanel(panelBottom);

    panelStats = guiManager->CreateWidget<RP::GuiPanel>();
    panelStats->SetSize(300, 200);
    panelStats->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    
    panelDelay = guiManager->CreateWidget<RP::GuiPanel>();
    panelDelay->SetSize(300, 200);
    panelDelay->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panelDelay->SetPaddingBetweenChildren(20);

    panelAlgorithms = guiManager->CreateWidget<RP::GuiPanel>();
    panelAlgorithms->SetPaddingBetweenChildren(20);
    panelAlgorithms->SetAlignItems(RP::AlignItems::Row);
    panelAlgorithms->SetSize(panelBottom->GetWidth() - panelStats->GetWidth() - panelDelay->GetWidth(), 150);
    panelAlgorithms->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);

    panelBottom->AddChild(panelAlgorithms);
    panelBottom->AddChild(panelDelay);
    panelBottom->AddChild(panelStats);
}

void SortingAlgorithmsScene::initButtons() const {
    std::function callbackInsertionSort = [this] { sortGui->Start(SortingAlgorithm::InsertionSort); };
    const RP::GuiButtonTextPtr btnInsertionSort = guiManager->CreateWidget<RP::GuiButtonText>(callbackInsertionSort, "Insertion Sort", font);
    btnInsertionSort->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    btnInsertionSort->SetSize(225, 50);
    btnInsertionSort->SetBackgroundColor({ 169, 215, 246, 255 });
    btnInsertionSort->SetPadding(10);
    panelAlgorithms->AddChild(btnInsertionSort);

    std::function callbackBubbleSort = [this] { sortGui->Start(SortingAlgorithm::BubbleSort); };
    const RP::GuiButtonTextPtr btnBubbleSort = guiManager->CreateWidget<RP::GuiButtonText>(callbackBubbleSort, "Bubble Sort", font);
    btnBubbleSort->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    btnBubbleSort->SetSize(225, 50);
    btnBubbleSort->SetBackgroundColor({ 169, 215, 246, 255 });
    btnBubbleSort->SetPadding(10);
    panelAlgorithms->AddChild(btnBubbleSort);

    std::function callbackQuickSort = [this] { sortGui->Start(SortingAlgorithm::QuickSort); };
    const RP::GuiButtonTextPtr btnQuickSort = guiManager->CreateWidget<RP::GuiButtonText>(callbackQuickSort, "Quick Sort", font);
    btnQuickSort->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    btnQuickSort->SetSize(225, 50);
    btnQuickSort->SetBackgroundColor({ 169, 215, 246, 255 });
    btnQuickSort->SetPadding(10);
    panelAlgorithms->AddChild(btnQuickSort);

    std::function callbackDelay1 = [this] { delayInMs = 1; };
    const RP::GuiButtonTextPtr btnDelay1 = guiManager->CreateWidget<RP::GuiButtonText>(callbackDelay1, "Delay 1 ms", font);
    btnDelay1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    btnDelay1->SetSize(175, 35);
    btnDelay1->SetBackgroundColor({ 169, 215, 246, 255 });
    btnDelay1->SetPadding(10);
    panelDelay->AddChild(btnDelay1);

    std::function callbackDelay10 = [this] { delayInMs = 10; };
    const RP::GuiButtonTextPtr btnDelay10 = guiManager->CreateWidget<RP::GuiButtonText>(callbackDelay10, "Delay 10 ms", font);
    btnDelay10->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    btnDelay10->SetSize(175, 35);
    btnDelay10->SetBackgroundColor({ 169, 215, 246, 255 });
    btnDelay10->SetPadding(10);
    panelDelay->AddChild(btnDelay10);

    std::function callbackDelay100 = [this] { delayInMs = 100; };
    const RP::GuiButtonTextPtr btnDelay100 = guiManager->CreateWidget<RP::GuiButtonText>(callbackDelay100, "Delay 100 ms", font);
    btnDelay100->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    btnDelay100->SetSize(175, 35);
    btnDelay100->SetBackgroundColor({ 169, 215, 246, 255 });
    btnDelay100->SetPadding(10);
    panelDelay->AddChild(btnDelay100);
}

void SortingAlgorithmsScene::Draw() {
    Scene::Draw();
    sortGui->Draw();
}

// *************************************************
// -------------------------------------------------
//               SORTING ALGORITHMS
// -------------------------------------------------
// *************************************************

void InsertionSort(std::vector<int>& values, const std::atomic<bool>& forceStop) {
    const int numberOfValues = static_cast<int>(values.size());
    int i = 1;
    while (i < numberOfValues) {
        int j = i;
        while (j > 0 && values[j - 1] > values[j]) {
            if (forceStop) { return; }
            Swap(values, j, j - 1);
            j--;
        }
        i++;
    }
}

void BubbleSort(std::vector<int>& values, const std::atomic<bool>& forceStop) {
    const int numberOfValues = static_cast<int>(values.size());
    for (int i = 0; i < numberOfValues - 1; i++) {
        for (int j = 0; j < numberOfValues - i - 1; j++) {
            if (forceStop) { return; }
            if (values[j] > values[j + 1]) {
                Swap(values, j, j + 1);
            }
        }
    }
}

int QuickSortPartition(std::vector<int>& values, const int start, const int end, const std::atomic<bool>& forceStop) {
    const int pivot = values[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (forceStop) { return 0; }
        if (values[i] <= pivot) {
            count++;
        }
    }
    const int pivotIndex = start + count;
    Swap(values, pivotIndex, start);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        if (forceStop) { return 0; }
        while (values[i] <= pivot) {
            i++;
        }
        while (values[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            Swap(values, i++, j--);
        }
    }
    return pivotIndex;
}

void QuickSort(std::vector<int>& values, const int start, const int end, const std::atomic<bool>& forceStop) {
    if (start >= end || forceStop)
        return;

    const int p = QuickSortPartition(values, start, end, forceStop);
    QuickSort(values, start, p - 1, forceStop);
    QuickSort(values, p + 1, end, forceStop);
}

void Swap(std::vector<int>& values, const int firstIndex, const int secondIndex) {
    const int v1 = values[firstIndex];
    const int v2 = values[secondIndex];
    values[secondIndex] = v1;
    values[firstIndex] = v2;
    SDL_Delay(delayInMs);
}