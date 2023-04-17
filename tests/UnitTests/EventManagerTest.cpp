#include <gtest/gtest.h>

#include <RP/Core/Managers/EventManager.hpp>

using namespace RP;

class EventManagerTest : public ::testing::Test {
protected:
    EventManager eventManager{};
    bool setValueCalled = false;
    int x = 0;

public:
    void SetValue() {
        setValueCalled = true;
    }

    void SetValue(int x) {
        this->x = x;
    }
};

TEST_F(EventManagerTest, AddAndDispatchSimpleEvent) {
    eventManager.Bind<void()>(1, [this] { SetValue(); });
    EXPECT_FALSE(setValueCalled);
    eventManager.Dispatch<void()>(1);
    EXPECT_TRUE(setValueCalled);
}

TEST_F(EventManagerTest, AddAndDispatchComplexEvent) {
    eventManager.Bind<void(int)>(2, [this](int a) { SetValue(a); });
    EXPECT_TRUE(x == 0);
    eventManager.Dispatch<void(int)>(2, 19);
    EXPECT_TRUE(x == 19);
}

TEST(EventManagerDeath, DipatchUnknownEvent) {
    EventManager em{};
    ASSERT_DEATH({
        em.Dispatch<void()>(1);
    }, "");
}