#ifndef DEMO_SORT_HPP
#define DEMO_SORT_HPP

#include <thread>
#include <atomic>

#include <RP/RP.hpp>

enum class SortingAlgorithm {
    InsertionSort,
    BubbleSort,
    QuickSort
};

class SortGui {
public:
    SortGui(SDL_Renderer* renderer, int x, int y, int width, int height);

    void Draw() const;
    void Start(SortingAlgorithm sortingAlgorithm);
    void StopSort();

private:
    void drawValues() const;
    void generateRandomValues();
    void startSort();

    SDL_Renderer* renderer = nullptr;
    int numberOfValues{};
    std::vector<int> values{};
    SortingAlgorithm actualAlgorithm{};
    SDL_Rect workingRectangle;
    std::thread sortingThread{};
    std::atomic<bool> forceStop{false};
};

class SortingAlgorithmsScene final : public RP::Scene {
public:
    SortingAlgorithmsScene(SDL_Renderer* renderer, RP::SpriteSheetPtr spriteSheet, RP::FontPtr font);

private:
    void initPanels();
    void initButtons() const;
    void initSortingAlgortihmsButtons() const;
    void initDelaysButtons() const;

    void Draw() override;
    
    RP::SpriteSheetPtr spriteSheet = nullptr;
    RP::FontPtr font = nullptr;
    RP::GuiPanel* panelAlgorithms = nullptr;
    RP::GuiPanel* panelBottom = nullptr;
    RP::GuiPanel* panelDelay = nullptr;
    RP::GuiPanel* panelStats = nullptr;
    std::shared_ptr<SortGui> sortGui = nullptr;
};

void Swap(std::vector<int>& values, int firstIndex, int secondIndex);
void InsertionSort(std::vector<int>& values, const std::atomic<bool>& forceStop);
void BubbleSort(std::vector<int>& values, const std::atomic<bool>& forceStop);
int QuickSortPartition(std::vector<int>& values, int start, int end, const std::atomic<bool>& forceStop);
void QuickSort(std::vector<int>& values, int start, int end, const std::atomic<bool>& forceStop);

#endif // DEMO_SORT_HPP