#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <Core/Coordinator.hpp>

TEST(Coordinator, EntityWithComponent) {
    Coordinator c{};
    c.RegisterComponent<ComponentTest>();
    Entity entity = c.CreateEntity();
    c.AddComponent<ComponentTest>(entity, ComponentTest{5});
    ComponentTest ct = c.GetComponent<ComponentTest>(entity);
    EXPECT_EQ(ct.x, 5);
    ComponentType ctype = c.GetComponentType<ComponentTest>();
    EXPECT_EQ(ctype, 0);
}

TEST(Coordinator, EntityInSystem) {
    Coordinator c{};
    c.RegisterComponent<ComponentTest>();
    std::shared_ptr<SystemTest> system = c.RegisterSystem<SystemTest>();
    Signature signature{};
    signature.set(c.GetComponentType<ComponentTest>());
    c.SetSystemSignature<SystemTest>(signature);
    EXPECT_EQ(system->Entities.size(), 0);
    Entity entity = c.CreateEntity();
    c.AddComponent<ComponentTest>(entity, ComponentTest{5});
    EXPECT_EQ(system->Entities.size(), 1);
}