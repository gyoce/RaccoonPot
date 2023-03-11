#include <gtest/gtest.h>

#include <Core/Managers/SystemManager.hpp>

using namespace GameEngine;

TEST(SystemManager, RegisterSystem) {
    SystemManager sm{};
    std::shared_ptr<System> system = sm.RegisterSystem<System>();
    EXPECT_TRUE(system != nullptr);
}

TEST(SystemManager, EntitySignatureChangedAndEntityDestroyed) {
    Entity entity {0};
    Signature signature {0b0100};
    SystemManager sm{};
    std::shared_ptr<System> system = sm.RegisterSystem<System>();
    sm.SetSignature<System>(signature);
    sm.EntitySignatureChanged(entity, signature);
    EXPECT_EQ(system->Entities.size(), 1);
    sm.EntityDestroyed(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}

TEST(SystemManagerDeath, RegisterSystemTwice) {
    SystemManager sm{};
    std::shared_ptr<System> system = sm.RegisterSystem<System>();
    ASSERT_DEATH({
        sm.RegisterSystem<System>();
    }, "");
}

TEST(SystemManagerDeath, SetSignatureBeforeRegistered) {
    SystemManager sm{};
    Signature signature{};
    ASSERT_DEATH({
        sm.SetSignature<System>(signature);
    }, "");
}