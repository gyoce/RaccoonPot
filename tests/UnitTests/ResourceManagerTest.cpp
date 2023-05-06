#include <gtest/gtest.h>

#include <CommonTypes.hpp>

const std::string ValidPathOfFont = "res/orange_kid.ttf";
const std::string ValidPathOfSpriteSheet = "res/SpriteSheet.png";

class ResourceManagerTest: public testing::Test {
protected:
    ResourceManagerTest() = default;
    ~ResourceManagerTest() override {
        resourceManager.reset();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
    }

    RP_DELETE_MISC_CONSTRUCTORS(ResourceManagerTest)
    
    void SetUp() override {
        TTF_Init();
        SDL_CreateWindowAndRenderer(32, 32, SDL_WINDOW_HIDDEN, &window, &renderer);
        resourceManager = std::make_shared<RP::ResourceManager>();
    }

    RP::ResourceManagerPtr resourceManager = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

TEST_F(ResourceManagerTest, UnknownFontPath) {
    const RP::FontPtr font = resourceManager->LoadFont("UnknownPath.to.file", "MyFont", 18);
    EXPECT_TRUE(font == nullptr);
}

TEST_F(ResourceManagerTest, UnknownSpriteSheetPath) {
    const RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet("UnknownPath.to.file", "MySpriteSheet", renderer);
    EXPECT_TRUE(spriteSheet == nullptr);
}

TEST_F(ResourceManagerTest, KnownFont) {
    const RP::FontPtr font = resourceManager->LoadFont(ValidPathOfFont, "MyFont", 18);
    EXPECT_TRUE(font != nullptr);
}

TEST_F(ResourceManagerTest, KnownSpriteSheet) {
    const RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet(ValidPathOfSpriteSheet, "MySpriteSheet", renderer);
    EXPECT_TRUE(spriteSheet != nullptr);
}

#ifndef NDEBUG

TEST(ResourceManagerDeath, SameNameForFont) {
    TTF_Init();
    // Have to early release ResourceManager because the destructor of font is called after
    // the TTF_Quit which cause to have a segmentation fault because the resources associated
    // with the SDL_TTF are released
    {
        RP::ResourceManager rm{};
        rm.LoadFont(ValidPathOfFont, "MyFont", 18);
        ASSERT_DEATH({
            rm.LoadFont(ValidPathOfFont, "MyFont", 18);
        }, "");
    }
    TTF_Quit();
}

TEST(ResourceManagerDeath, SameNameForSpriteSheet) {
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    SDL_CreateWindowAndRenderer(32, 32, SDL_WINDOW_HIDDEN, &window, &renderer);
    RP::ResourceManager rm{};
    rm.LoadSpriteSheet(ValidPathOfSpriteSheet, "MySpriteSheet", renderer);
    ASSERT_DEATH({
        rm.LoadSpriteSheet(ValidPathOfSpriteSheet, "MySpriteSheet", renderer);
    }, "");
}

#endif // NDEBUG