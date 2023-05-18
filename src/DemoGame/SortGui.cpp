#include "SortGui.hpp"

#include <random>

SortGui::SortGui(const int x, const int y, const  int width, const  int height)
    : workingRectangle(x, y, width, height) {
    numberOfValues = width / (sizeOfEachValue + paddingBetweenValues);
}

void SortGui::SetUp(const SortingAlgorithm sortingAlgorithm) {
    this->actualAlgorithm = sortingAlgorithm;
    generateRandomValues();
    ready = true;
}

bool SortGui::Ready() const {
    return ready;
}

void SortGui::Start() {
    start = true;
}

void SortGui::Draw(SDL_Renderer* renderer) {
    if (actualAlgorithm == SortingAlgorithm::None) {
        return;
    }
    SDL_Color color;
    SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
    drawValues(renderer);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void SortGui::Update(const double dt) {
    if (!start) {
        return;
    }
    timer += dt;
    if (timer > delay) {
        timer = 0;
        insertionSort();
    }
}

void SortGui::insertionSort() {
    int i = 1;
    while (i < numberOfValues) {
        int j = i;
        while (j > 0 && values[j - 1] > values[j]) {
            const int v1 = values[j];
            const int v2 = values[j - 1];
            values[j - 1] = v1;
            values[j] = v2;
            j--;
            return;
        }
        i++;
    }
}

void SortGui::drawValues(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < numberOfValues; i++) {
        const int value = values[i];
        const SDL_Rect rect{
            workingRectangle.x + paddingBetweenValues + (sizeOfEachValue + paddingBetweenValues) * i,
            workingRectangle.y + workingRectangle.h - value,
            sizeOfEachValue,
            value
        };
        SDL_RenderFillRect(renderer, &rect);
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