#ifndef GAME_SORT_HPP
#define GAME_SORT_HPP

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

    void SetUp(SortingAlgorithm sortingAlgorithm);
    void StopSort();

private:
    void drawValues() const;
    void generateRandomValues();

    void start();
    void startSort();

    void insertionSort();
    void bubbleSort();
    void quicksort(int start, int end);

    void swap(int firstIndex, int secondIndex);
    int quicksortPartition(int start, int end);

    SDL_Renderer* renderer = nullptr;
    int numberOfValues{};
    std::vector<int> values{};
    SortingAlgorithm actualAlgorithm{};
    SDL_Rect workingRectangle;
    std::thread sortingThread{};
    std::atomic<bool> forceStop{false};
};

#endif // GAME_SORT_HPP