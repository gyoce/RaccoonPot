#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <Core/Coordinator.hpp>

using namespace ECSGameEngine;

class CoordinatorTest : public ::testing::Test {
protected:
    Coordinator coordinator{};
    std::shared_ptr<SystemTest> system = nullptr;

    void SetUp() override {
        coordinator.RegisterComponent<ComponentTest>();
        system = coordinator.RegisterSystem<SystemTest>();
        Signature signature{};
        signature.set(coordinator.GetComponentType<ComponentTest>());
        coordinator.SetSystemSignature<SystemTest>(signature);
        coordinator.SetSystemSignature<SystemTest>(signature);
    }
};

TEST_F(CoordinatorTest, EntityWithComponent) {
    Entity entity = coordinator.CreateEntity();
    coordinator.AddComponent<ComponentTest>(entity, ComponentTest{5 });
    ComponentTest ct = coordinator.GetComponent<ComponentTest>(entity);
    EXPECT_EQ(ct.x, 5);
    ComponentType componentType = coordinator.GetComponentType<ComponentTest>();
    EXPECT_EQ(componentType, 0);
}

TEST_F(CoordinatorTest, EntityInSystem) {
    Entity entity = coordinator.CreateEntity();
    coordinator.AddComponent<ComponentTest>(entity, ComponentTest{5 });
    EXPECT_EQ(system->Entities.size(), 1);
    coordinator.RemoveComponent<ComponentTest>(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}

TEST_F(CoordinatorTest, EntityDestroyed) {
    Entity entity = coordinator.CreateEntity();
    coordinator.AddComponent<ComponentTest>(entity, ComponentTest{5 });
    EXPECT_EQ(system->Entities.size(), 1);
    coordinator.DestroyEntity(entity);
    EXPECT_EQ(system->Entities.size(), 0);
}