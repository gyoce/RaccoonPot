#include <gtest/gtest.h>

#include <CommonTypes.hpp>

TEST(SpriteSheet, ExtratAllTextureCorrectly) {
    const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
    const std::vector<std::pair<std::string, SDL_Rect>> spriteSheetInfos = {
        { "SameName", { 0, 0, 16, 16 }},
        { "SameName2", { 0, 16, 32, 32 }}
    };

    RP::SpriteSheet spriteSheet{ commonTestData->Texture, commonTestData->Renderer, spriteSheetInfos };
    for(auto const& [first, second] : spriteSheetInfos) {
        SDL_Texture* texture = spriteSheet.GetTextureByName(first);
        int width, height;
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
        EXPECT_EQ(width, second.w); EXPECT_EQ(height, second.h);
    }
}

#ifndef NDEBUG

TEST(SpriteSheetDeath, SameNameForSpriteTexture) {
    const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
    const std::vector<std::pair<std::string, SDL_Rect>> spriteSheetInfos = {
        { "SameName", { 0, 0, 1, 1 }},
        { "SameName", { 0, 0, 1, 1 }}
    };

    ASSERT_DEATH({
        RP::SpriteSheet(commonTestData->Texture, commonTestData->Renderer, spriteSheetInfos);
    }, "");
}

TEST(SpriteSheetDeath, GetTextureByUnknownName) {
    const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
    const std::vector<std::pair<std::string, SDL_Rect>> spriteSheetInfos = { { "SameName", { 0, 0, 1, 1 }} };
    RP::SpriteSheet spriteSheet{ commonTestData->Texture, commonTestData->Renderer, spriteSheetInfos };
    ASSERT_DEATH({
        spriteSheet.GetTextureByName("UnknownName");
    }, "");
}

#endif // NDEBUG