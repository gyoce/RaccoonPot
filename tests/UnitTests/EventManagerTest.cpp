#include <gtest/gtest.h>

#include <RP/Core/Managers/EventManager.hpp>

using namespace RP;

class EventManagerTest : public ::testing::Test {
protected:
    EventManager eventManager{};
    bool setValueCalled = false;

public:
    void SetValue() {
        setValueCalled = true;
    }
};

TEST_F(EventManagerTest, AddAndDispatchEvent) {
    std::function<void()> fct = [this] { SetValue(); };
    eventManager.Bind(1, fct);
    EXPECT_FALSE(setValueCalled);
    eventManager.Dispatch(1);
    EXPECT_TRUE(setValueCalled);
}

TEST(EventManagerDeath, DipatchUnknownEvent) {
    EventManager em{};
    ASSERT_DEATH({
        em.Dispatch(1);
    }, "");
}