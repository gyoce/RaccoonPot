#include "SortGui.hpp"

#include <random>

constexpr int SizeOfEachValue = 10;
constexpr int PaddingBetweenValues = 5;
constexpr int DelayInMs = 25;

SortGui::SortGui(SDL_Renderer* renderer, const int x, const int y, const  int width, const  int height)
    : renderer(renderer), workingRectangle(x, y, width, height) {
    numberOfValues = width / (SizeOfEachValue + PaddingBetweenValues);
}

void SortGui::SetUp(const SortingAlgorithm sortingAlgorithm) {
    this->actualAlgorithm = sortingAlgorithm;
    StopSort();
    generateRandomValues();
    start();
}

void SortGui::start() {
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
        insertionSort();
        break;
    case SortingAlgorithm::BubbleSort:
        bubbleSort();
        break;
    case SortingAlgorithm::QuickSort:
        quicksort(0, numberOfValues - 1);
        break;
    }
}

void SortGui::insertionSort() {
    int i = 1;
    while (i < numberOfValues) {
        int j = i;
        while (j > 0 && values[j - 1] > values[j]) {
            if (forceStop) { return; }
            swap(j, j - 1);
            j--;
        }
        i++;
    }
}

void SortGui::bubbleSort() {
    for (int i = 0; i < numberOfValues - 1; i++) {
        for (int j = 0; j < numberOfValues - i - 1; j++) {
            if (forceStop) { return; }
            if (values[j] > values[j + 1]) {
                swap(j, j + 1);
            }
        }
    }
}

void SortGui::quicksort(const int start, const int end) {
    if (start >= end || forceStop)
        return;

    const int p = quicksortPartition(start, end);
    quicksort(start, p - 1);
    quicksort(p + 1, end);
}

int SortGui::quicksortPartition(const int start, const int end) {
    const int pivot = values[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (forceStop) { return 0; }
        if (values[i] <= pivot) {
            count++;
        }
    }
    const int pivotIndex = start + count;
    swap(pivotIndex, start);
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
            swap(i++, j--);
        }
    }
    return pivotIndex;
}

void SortGui::swap(const int firstIndex, const int secondIndex) {
    const int v1 = values[firstIndex];
    const int v2 = values[secondIndex];
    values[secondIndex] = v1;
    values[firstIndex] = v2;
    SDL_Delay(DelayInMs);
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