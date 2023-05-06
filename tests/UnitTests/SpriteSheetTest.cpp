#include <gtest/gtest.h>

#include <CommonTypes.hpp>

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

#endif // NDEBUG