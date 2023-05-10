#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <RP/Core/Managers/SystemManager.hpp>

TEST(SystemManager, RegisterSystem) {
    RP::SystemManager sm{};
    const std::shared_ptr<SystemTest> system = sm.RegisterSystem<SystemTest>();
    EXPECT_TRUE(system != nullptr);
}

TEST(SystemManager, EntitySignatureChangedAndEntityDestroyed) {
    constexpr RP::Entity entity{ 0 };
    constexpr RP::Signature signature{ 0b0100 };
    RP::SystemManager sm{};
    const std::shared_ptr<SystemTest> system = sm.RegisterSystem<SystemTest>();
    sm.SetSignature<SystemTest>(signature);
    sm.EntitySignatureChanged(entity, signature);
    EXPECT_EQ(system->Entities.size(), 1);
    sm.EntityDestroyed(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}

#ifndef NDEBUG

TEST(SystemManagerDeath, RegisterSystemTwice) {
    RP::SystemManager sm{};
    std::shared_ptr<SystemTest> system = sm.RegisterSystem<SystemTest>();
    ASSERT_DEATH({
        sm.RegisterSystem<SystemTest>();
    }, "");
}

TEST(SystemManagerDeath, SetSignatureBeforeRegistered) {
    RP::SystemManager sm{};
    const RP::Signature signature{};
    ASSERT_DEATH({
        sm.SetSignature<SystemTest>(signature);
    }, "");
}

#endif // NDEBUG