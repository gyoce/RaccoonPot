#include <gtest/gtest.h>

#include <CommonTypes.hpp>

TEST(ComponentArray, AssociateDataForComponent) {
    constexpr RP::Entity entity = 0;
    RP::ComponentArray<ComponentTest> ca{};
    ca.InsertData(entity, ComponentTest{ 5 });
    const ComponentTest ct = ca.GetData(0);
    EXPECT_EQ(ct.x, 5);
}

#ifndef NDEBUG

TEST(ComponentArrayDeath, RemoveDataNotInserted) {
    constexpr RP::Entity entity = 0;
    RP::ComponentArray<ComponentTest> ca{};
    ASSERT_DEATH({
        ca.RemoveData(entity);
    }, "");
}

TEST(ComponentArrayDeath, AddComponentTwice) {
    constexpr RP::Entity entity = 0;
    RP::ComponentArray<ComponentTest> ca{};
    ca.InsertData(entity, ComponentTest{});
    ASSERT_DEATH({
        ca.InsertData(entity, ComponentTest{});
    }, "");
}

TEST(ComponentArrayDeath, GetComponentAfterEntityDestroyed) {
    constexpr RP::Entity entity = 0;
    RP::ComponentArray<ComponentTest> ca{};
    ca.InsertData(entity, ComponentTest{});
    ca.EntityDestroyed(entity);
    ASSERT_DEATH({
        ca.GetData(entity);
    }, "");
}

#endif // NDEBUG