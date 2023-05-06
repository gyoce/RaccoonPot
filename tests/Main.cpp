#define SDL_MAIN_HANDLED

#include <gtest/gtest.h>

#include <CommonTestData.hpp>

int main(int argc, char** argv) {
    const CommonTestDataPtr commonTestData = CommonTestData::GetInstance();
    testing::InitGoogleTest(&argc, argv);
    const int result = RUN_ALL_TESTS();
    delete commonTestData;
    return result;
}