#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <Core/Managers/SystemManager.hpp>

using namespace EcsGameEngine;

TEST(SystemManager, RegisterSystem) {
    SystemManager sm{};
    std::shared_ptr<SystemTest> system = sm.RegisterSystem<SystemTest>();
    EXPECT_TRUE(system != nullptr);
}

TEST(SystemManager, EntitySignatureChangedAndEntityDestroyed) {
    Entity entity{ 0 };
    Signature signature{ 0b0100 };
    SystemManager sm{};
    std::shared_ptr<SystemTest> system = sm.RegisterSystem<SystemTest>();
    sm.SetSignature<SystemTest>(signature);
    sm.EntitySignatureChanged(entity, signature);
    EXPECT_EQ(system->Entities.size(), 1);
    sm.EntityDestroyed(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}

TEST(SystemManagerDeath, RegisterSystemTwice) {
    SystemManager sm{};
    std::shared_ptr<SystemTest> system = sm.RegisterSystem<SystemTest>();
    ASSERT_DEATH({
        sm.RegisterSystem<SystemTest>();
    }, "");
}

TEST(SystemManagerDeath, SetSignatureBeforeRegistered) {
    SystemManager sm{};
    Signature signature{};
    ASSERT_DEATH({
        sm.SetSignature<SystemTest>(signature);
    }, "");
}