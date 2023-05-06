#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <RP/RP.hpp>

class CoordinatorTest : public ::testing::Test {
protected:
    RP::Coordinator coordinator{};
    RP::SystemPtr system = nullptr;

    void SetUp() override {
        coordinator.RegisterComponent<ComponentTest>();
        system = coordinator.RegisterSystem<SystemTest>();
        RP::Signature signature{};
        signature.set(coordinator.GetComponentType<ComponentTest>());
        coordinator.SetSystemSignature<SystemTest>(signature);
    }
};

TEST_F(CoordinatorTest, EntityWithComponent) {
    const RP::Entity entity = coordinator.CreateEntity();
    coordinator.AddComponent<ComponentTest>(entity, ComponentTest{ 5 });
    const ComponentTest ct = coordinator.GetComponent<ComponentTest>(entity);
    EXPECT_EQ(ct.x, 5);
    const RP::ComponentType componentType = coordinator.GetComponentType<ComponentTest>();
    EXPECT_EQ(componentType, 0);
}

TEST_F(CoordinatorTest, EntityInSystem) {
    const RP::Entity entity = coordinator.CreateEntity();
    coordinator.AddComponent<ComponentTest>(entity, ComponentTest{ 5 });
    EXPECT_EQ(system->Entities.size(), 1);
    coordinator.RemoveComponent<ComponentTest>(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}

TEST_F(CoordinatorTest, EntityDestroyed) {
    const RP::Entity entity = coordinator.CreateEntity();
    coordinator.AddComponent<ComponentTest>(entity, ComponentTest{ 5 });
    EXPECT_EQ(system->Entities.size(), 1);
    coordinator.DestroyEntity(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}