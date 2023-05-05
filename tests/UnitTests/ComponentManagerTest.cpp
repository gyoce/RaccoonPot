#include <gtest/gtest.h>

#include <CommonTypes.hpp>

TEST(ComponentManager, GetComponentType) {
    RP::Entity entity = 0;
    RP::ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    RP::ComponentType component = cm.GetComponentType<ComponentTest>();
    EXPECT_EQ(component, entity);
}

TEST(ComponentManager, AssociateComponentCorrectly) {
    RP::Entity entity = 0;
    RP::ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    cm.AddComponent(entity, ComponentTest{ 5 });
    ComponentTest ct = cm.GetComponent<ComponentTest>(entity);
    EXPECT_EQ(ct.x, 5);
}

#ifndef NDEBUG

TEST(ComponentManagerDeath, GetComponentAfterRemove) {
    RP::Entity entity = 0;
    RP::ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    cm.AddComponent(entity, ComponentTest{});
    cm.RemoveComponent<ComponentTest>(entity);
    ASSERT_DEATH({
        cm.GetComponent<ComponentTest>(entity);
    }, "");
}

TEST(ComponentManagerDeath, GetComponentAfterEntityDestroyed) {
    RP::Entity entity = 0;
    RP::ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    cm.AddComponent(entity, ComponentTest{});
    cm.EntityDestroyed(entity);
    ASSERT_DEATH({
        cm.GetComponent<ComponentTest>(entity);
    }, "");
}

TEST(ComponentManagerDeath, RegisterComponentTwice) {
    RP::ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    ASSERT_DEATH({
        cm.RegisterComponent<ComponentTest>();
    }, "");
}

TEST(ComponentManagerDeath, GetComponentTypeNotRegistered) {
    RP::ComponentManager cm{};
    ASSERT_DEATH({
        cm.GetComponentType<ComponentTest>();
    }, "");
}

TEST(ComponentManagerDeath, AddComponentNotRegistered) {
    RP::Entity entity = 0;
    RP::ComponentManager cm{};
    ASSERT_DEATH({
        cm.AddComponent(entity, ComponentTest{});
    }, "");
}

TEST(ComponentManagerDeath, RemoveComponentNotRegistered) {
    RP::Entity entity = 0;
    RP::ComponentManager cm{};
    ASSERT_DEATH({
        cm.RemoveComponent<ComponentTest>(entity);
    }, "");
}

#endif // NDEBUG