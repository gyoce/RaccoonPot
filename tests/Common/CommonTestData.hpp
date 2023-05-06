#ifndef TESTS_COMMON_TEST_DATA
#define TESTS_COMMON_TEST_DATA

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <RP/RPMacros.hpp>

class CommonTestData;
using CommonTestDataPtr = CommonTestData*;

class CommonTestData {
public:
    ~CommonTestData() {
        SDL_DestroyRenderer(Renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
        IMG_Quit();
        TTF_Quit();
    }

    RP_DELETE_MISC_CONSTRUCTORS(CommonTestData)

    static CommonTestDataPtr GetInstance() {
        if (instance == nullptr) {
            instance = new CommonTestData;
        }
        return instance;
    }

    SDL_Renderer* Renderer = nullptr;
    SDL_Window* Window = nullptr;
    SDL_Texture* Texture = nullptr;

private:
    static inline CommonTestData* instance = nullptr;

    CommonTestData() {
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        TTF_Init();
        SDL_CreateWindowAndRenderer(64, 64, SDL_WINDOW_HIDDEN, &Window, &Renderer);
        Texture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 128, 128);
    }
};

#endif // TESTS_COMMON_TEST_DATA