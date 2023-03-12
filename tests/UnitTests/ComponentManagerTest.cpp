#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <Core/Managers/ComponentManager.hpp>

using namespace ECSGameEngine;

TEST(ComponentManager, GetComponentType) {
    Entity entity = 0;
    ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    ComponentType component = cm.GetComponentType<ComponentTest>();
    EXPECT_EQ(component, entity);
}

TEST(ComponentManager, AssociateComponentCorrectly) {
    Entity entity = 0;
    ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    cm.AddComponent(entity, ComponentTest{5});
    ComponentTest ct = cm.GetComponent<ComponentTest>(entity);
    EXPECT_EQ(ct.x, 5);
}

TEST(ComponentManagerDeath, GetComponentAfterRemove) {
    Entity entity = 0;
    ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    cm.AddComponent(entity, ComponentTest{});
    cm.RemoveComponent<ComponentTest>(entity);
    ASSERT_DEATH({
        cm.GetComponent<ComponentTest>(entity);
    }, "");
}

TEST(ComponentManagerDeath, GetComponentAfterEntityDestroyed) {
    Entity entity = 0;
    ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    cm.AddComponent(entity, ComponentTest{});
    cm.EntityDestroyed(entity);
    ASSERT_DEATH({
        cm.GetComponent<ComponentTest>(entity);
    }, "");
}

TEST(ComponentManagerDeath, RegisterComponentTwice) {
    ComponentManager cm{};
    cm.RegisterComponent<ComponentTest>();
    ASSERT_DEATH({
        cm.RegisterComponent<ComponentTest>();
    }, "");
}

TEST(ComponentManagerDeath, GetComponentTypeNotRegistered) {
    ComponentManager cm{};
    ASSERT_DEATH({
        cm.GetComponentType<ComponentTest>();
    }, "");
}

TEST(ComponentManagerDeath, AddComponentNotRegistered) {
    Entity entity = 0;
    ComponentManager cm{};
    ASSERT_DEATH({
        cm.AddComponent(entity, ComponentTest{});
    }, "");
}

TEST(ComponentManagerDeath, RemoveComponentNotRegistered) {
    Entity entity = 0;
    ComponentManager cm{};
    ASSERT_DEATH({
        cm.RemoveComponent<ComponentTest>(entity);
    }, "");
}