#include <gtest/gtest.h>

#include <CommonTypes.hpp>

using namespace RP;

TEST(SceneManager, RegisterScene) {
    SceneManager sm{nullptr};
    sm.SetBaseAction(88);
    sm.RegisterScene<SceneTest>(88)->SetLoopReturn(10);
    EXPECT_EQ(sm.Loop(), 10);
}

TEST(SceneManager, ChangeOfScene) {
    SceneManager sm{nullptr};
    sm.SetBaseAction(33);
    sm.RegisterScene<SceneTest>(33)->SetLoopReturn(44);
    sm.RegisterScene<SceneTest2>(44)->SetLoopReturn(55);
    EXPECT_EQ(sm.Loop(), 55);
}

#ifndef NDEBUG

TEST(SceneManagerDeath, RegisterTwiceTheSameScene) {
    SceneManager sm{nullptr};
    sm.RegisterScene<SceneTest>(11);
    ASSERT_DEATH({
        sm.RegisterScene<SceneTest>(12);
    }, "");
}

TEST(SceneManagerDeath, RegisterTwiceTheSameAction) {
    SceneManager sm{nullptr};
    sm.RegisterScene<SceneTest>(11);
    ASSERT_DEATH({
        sm.RegisterScene<SceneTest2>(11);
    }, "");
}

TEST(SceneManagerDeath, LoopWithoutBaseActionScene) {
    SceneManager sm{nullptr};
    ASSERT_DEATH({
        sm.Loop();
    }, "");
}

#endif // NDEBUG