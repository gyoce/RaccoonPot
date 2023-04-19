#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <RP/RP.hpp>

using namespace RP;

TEST(SceneManager, RegisterScene) {
    SceneManager sm{ 88 }; 
    sm.RegisterScene<SceneTest>(88)->SetLoopReturn(10);
    EXPECT_TRUE(sm.Loop() == 10);
}

TEST(SceneManager, ChangeOfScene) {
    SceneManager sm{ 33 };
    sm.RegisterScene<SceneTest>(33)->SetLoopReturn(44);
    sm.RegisterScene<SceneTest2>(44)->SetLoopReturn(55);
    EXPECT_TRUE(sm.Loop() == 55);
}

TEST(SceneManagerDeath, RegisterTwiceTheSameScene) {
    SceneManager sm{ 11 };
    sm.RegisterScene<SceneTest>(11);
    ASSERT_DEATH({
        sm.RegisterScene<SceneTest>(12);
    }, "");
}

TEST(SceneManagerDeath, RegisterTwiceTheSameAction) {
    SceneManager sm{ 11 };
    sm.RegisterScene<SceneTest>(11);
    ASSERT_DEATH({
        sm.RegisterScene<SceneTest2>(11);
    }, "");
}

TEST(SceneManagerDeath, LoopWithoutBaseActionScene) {
    SceneManager sm{ 11 };
    ASSERT_DEATH({
        sm.Loop();
    }, "");
}