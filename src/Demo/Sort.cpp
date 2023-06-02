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
    drawValues();
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
    panelBottom = new RP::GuiPanel();
    panelBottom->SetBackgroundColor({ 249, 109, 109, 255 });
    panelBottom->SetSize(Options.Width, 200);
    panelBottom->SetVerticalAnchor(RP::VerticalAnchor::Bottom);
    panelBottom->SetAlignItems(RP::AlignItems::Row);
    guiManager->AddToMainPanel(panelBottom);

    panelStats = new RP::GuiPanel();
    panelStats->SetSize(300, 200);
    panelStats->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    
    panelDelay = new RP::GuiPanel();
    panelDelay->SetSize(300, 200);
    panelDelay->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panelDelay->SetPaddingBetweenChildren(20);

    panelAlgorithms = new RP::GuiPanel();
    panelAlgorithms->SetPaddingBetweenChildren(20);
    panelAlgorithms->SetAlignItems(RP::AlignItems::Row);
    panelAlgorithms->SetSize(panelBottom->GetWidth() - panelStats->GetWidth() - panelDelay->GetWidth(), 150);
    panelAlgorithms->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);

    panelBottom->AddChild(panelAlgorithms);
    panelBottom->AddChild(panelDelay);
    panelBottom->AddChild(panelStats);
}

void SortingAlgorithmsScene::initButtons() const {
    initSortingAlgortihmsButtons();
    initDelaysButtons();
}

void SortingAlgorithmsScene::initSortingAlgortihmsButtons() const {
    RP::GuiBuilder<RP::GuiButtonText> buttonTextBuilder{};
    buttonTextBuilder->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    buttonTextBuilder->SetSize(225, 50);
    buttonTextBuilder->SetBackgroundColor({ 169, 215, 246, 255 });
    buttonTextBuilder->SetPadding(10);
    buttonTextBuilder->SetHoverable(true);

    const std::function callbackInsertionSort = [this] { sortGui->Start(SortingAlgorithm::InsertionSort); };
    auto* btnInsertionSort = buttonTextBuilder.Build();
    btnInsertionSort->SetCallback(callbackInsertionSort);
    btnInsertionSort->SetText("Insertion Sort", font);
    panelAlgorithms->AddChild(btnInsertionSort);

    const std::function callbackBubbleSort = [this] { sortGui->Start(SortingAlgorithm::BubbleSort); };
    auto* btnBubbleSort = buttonTextBuilder.Build();
    btnBubbleSort->SetCallback(callbackBubbleSort);
    btnBubbleSort->SetText("Bubble Sort", font);
    panelAlgorithms->AddChild(btnBubbleSort);

    const std::function callbackQuickSort = [this] { sortGui->Start(SortingAlgorithm::QuickSort); };
    auto* btnQuickSort = buttonTextBuilder.Build();
    btnQuickSort->SetCallback(callbackQuickSort);
    btnQuickSort->SetText("Quick Sort", font);
    panelAlgorithms->AddChild(btnQuickSort);
}


void SortingAlgorithmsScene::initDelaysButtons() const {
    RP::GuiBuilder<RP::GuiButtonText> buttonTextBuilder{};
    buttonTextBuilder->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    buttonTextBuilder->SetSize(175, 35);
    buttonTextBuilder->SetBackgroundColor({ 169, 215, 246, 255 });
    buttonTextBuilder->SetPadding(10);
    buttonTextBuilder->SetHoverable(true);

    const std::function callbackDelay1 = [this] { delayInMs = 1; };
    auto* btnDelay1 = buttonTextBuilder.Build();
    btnDelay1->SetCallback(callbackDelay1);
    btnDelay1->SetText("Delay 1 ms", font);
    panelDelay->AddChild(btnDelay1);

    const std::function callbackDelay10 = [this] { delayInMs = 10; };
    auto* btnDelay10 = buttonTextBuilder.Build();
    btnDelay10->SetCallback(callbackDelay10);
    btnDelay10->SetText("Delay 10 ms", font);
    panelDelay->AddChild(btnDelay10);

    const std::function callbackDelay100 = [this] { delayInMs = 100; };
    auto* btnDelay100 = buttonTextBuilder.Build();
    btnDelay100->SetCallback(callbackDelay100);
    btnDelay100->SetText("Delay 100 ms", font);
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