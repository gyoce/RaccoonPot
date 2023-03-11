#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <Core/Components/ComponentArray.hpp>

using namespace GameEngine;

TEST(ComponentArray, AssociateDataForComponent) {
    Entity entity = 0;
    ComponentArray<ComponentTest> ca{};
    ca.InsertData(entity, ComponentTest{5});
    ComponentTest ct = ca.GetData(0);
    EXPECT_EQ(ct.x, 5);
}

TEST(ComponentArrayDeath, RemoveDataNotInserted) {
    Entity entity = 0;
    ComponentArray<ComponentTest> ca{};
    ASSERT_DEATH({
        ca.RemoveData(entity);
    }, "");
}

TEST(ComponentArrayDeath, AddComponentTwice) {
    Entity entity = 0;
    ComponentArray<ComponentTest> ca{};
    ca.InsertData(entity, ComponentTest{});
    ASSERT_DEATH({
        ca.InsertData(entity, ComponentTest{});
    }, "");
}

TEST(ComponentArrayDeath, GetComponentAfterEntityDestroyed) {
    Entity entity = 0;
    ComponentArray<ComponentTest> ca{};
    ca.InsertData(entity, ComponentTest{});
    ca.EntityDestroyed(entity);
    ASSERT_DEATH({
        ca.GetData(entity);
    }, "");
}