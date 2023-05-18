#ifndef GAME_SORT_HPP
#define GAME_SORT_HPP

#include <RP/RP.hpp>

enum class SortingAlgorithm {
    None,
    InsertionSort
};

class SortGui {
public:
    explicit SortGui(int x, int y, int width, int height);

    void Draw(SDL_Renderer* renderer);
    void Update(double dt);

    void SetUp(SortingAlgorithm sortingAlgorithm);
    bool Ready() const;
    void Start();

private:
    void drawValues(SDL_Renderer* renderer) const;
    void generateRandomValues();

    void insertionSort();

    const int sizeOfEachValue = 10;
    const int paddingBetweenValues = 5;
    const double delay = 0.01;
    double timer{};
    int numberOfValues{};
    std::vector<int> values{};
    SortingAlgorithm actualAlgorithm = SortingAlgorithm::None;
    SDL_Rect workingRectangle;
    bool ready{}, start{};
};

#endif // GAME_SORT_HPP