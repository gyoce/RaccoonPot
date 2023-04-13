#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <Core/Managers/SceneManager.hpp>

using namespace ECSGameEngine;

TEST(SceneManager, RegisterScene) {
	SceneManager sm{ 88 }; 
	SceneTest::LOOP_RETURN = 10;
	sm.RegisterScene<SceneTest>(88);
	EXPECT_TRUE(sm.Loop() == 10);
}

TEST(SceneManager, ChangeOfScene) {
	SceneManager sm{ 33 };
	SceneTest::LOOP_RETURN = 44;
	SceneTest2::LOOP_RETURN = 55;
	sm.RegisterScene<SceneTest>(33);
	sm.RegisterScene<SceneTest2>(44);
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