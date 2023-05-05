#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class EventManagerTest : public ::testing::Test {
protected:
    RP::EventManager eventManager{};
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