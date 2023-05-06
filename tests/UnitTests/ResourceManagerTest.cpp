#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class ResourceManagerTest: public testing::Test {
protected:    
    void SetUp() override {
        const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
        resourceManager = std::make_shared<RP::ResourceManager>(commonTestData->Renderer);
    }

    RP::ResourceManagerPtr resourceManager = nullptr;
};

TEST_F(ResourceManagerTest, UnknownFontPath) {
    const RP::FontPtr font = resourceManager->LoadFont("UnknownPath.to.file", "MyFont", 18);
    EXPECT_TRUE(font == nullptr);
}

TEST_F(ResourceManagerTest, UnknownSpriteSheetPath) {
    const std::vector<std::pair<std::string, SDL_Rect>> vector{};
    const RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet("UnknownPath.to.file", "MySpriteSheet", vector);
    EXPECT_TRUE(spriteSheet == nullptr);
}

TEST_F(ResourceManagerTest, KnownFont) {
    const RP::FontPtr font = resourceManager->LoadFont(ValidPathOfFont, "MyFont", 18);
    EXPECT_TRUE(font != nullptr);
}

TEST_F(ResourceManagerTest, KnownSpriteSheet) {
    const std::vector<std::pair<std::string, SDL_Rect>> vector{};
    const RP::SpriteSheetPtr spriteSheet = resourceManager->LoadSpriteSheet(ValidPathOfSpriteSheet, "MySpriteSheet", vector);
    EXPECT_TRUE(spriteSheet != nullptr);
}

#ifndef NDEBUG

TEST(ResourceManagerDeath, SameNameForFont) {
    const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
    RP::ResourceManager rm{ commonTestData->Renderer };
    rm.LoadFont(ValidPathOfFont, "MyFont", 18);
    ASSERT_DEATH({
        rm.LoadFont(ValidPathOfFont, "MyFont", 18);
    }, "");
}

TEST(ResourceManagerDeath, SameNameForSpriteSheet) {
    const std::vector<std::pair<std::string, SDL_Rect>> vector{};
    const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
    RP::ResourceManager rm{ commonTestData->Renderer };
    rm.LoadSpriteSheet(ValidPathOfSpriteSheet, "MySpriteSheet", vector);
    ASSERT_DEATH({
        rm.LoadSpriteSheet(ValidPathOfSpriteSheet, "MySpriteSheet", vector);
    }, "");
}

#endif // NDEBUG