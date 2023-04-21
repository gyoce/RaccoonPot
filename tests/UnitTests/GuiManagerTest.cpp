#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <RP/RP.hpp>

using namespace RP;

class GuiManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        eventManager = std::make_shared<EventManager>();
        guiManager.RegisterEventManager(eventManager);
        guiManager.RegisterRenderFunctionForWidget<WidgetTest>([this](const std::shared_ptr<WidgetTest>& widget) { DrawWidget(widget); });
        guiManager.RegisterClickEvent(1);
    }

    static void DrawWidget(std::shared_ptr<WidgetTest> widget) {
        widget->CallRenderFunction = true;
    }
    
    std::shared_ptr<EventManager> eventManager = nullptr;
    GuiManager guiManager{};
};

TEST_F(GuiManagerTest, CallRenderFunction) {
    std::shared_ptr<WidgetTest> widget = guiManager.CreateWidget<WidgetTest>(10);
    guiManager.Render();
    EXPECT_TRUE(widget->CallRenderFunction);
    EXPECT_EQ(widget->value, 10);
}

TEST_F(GuiManagerTest, CallClickEvent) {
    std::shared_ptr<WidgetTest> widget = guiManager.CreateWidget<WidgetTest>();
    widget->x = 100; widget->y = 100; widget->Width = 10; widget->Height = 10;
    eventManager->Dispatch<void(int, int)>(1, 10, 10); // Miss click
    EXPECT_FALSE(widget->CallClickFunction);
    eventManager->Dispatch<void(int, int)>(1, 101, 101); // Click inside
    EXPECT_TRUE(widget->CallClickFunction);
}

TEST(GuiManagerDeath, RegisterClickEventBeforeRegisterEventManager) {
    GuiManager guiManager{};
    ASSERT_DEATH({
        guiManager.RegisterClickEvent(1);
    }, "");
}

TEST(GuiManagerDeath, CreateWidgetBeforeRegister) {
    GuiManager guiManager{};
    ASSERT_DEATH({
        guiManager.CreateWidget<WidgetTest>();
    }, "");
}

TEST(GuiManagerDeath, RegisterWidgetTwice) {
    GuiManager guiManager{};
    guiManager.RegisterRenderFunctionForWidget<WidgetTest>([](const std::shared_ptr<WidgetTest>& widget) {  });
    ASSERT_DEATH({
        guiManager.RegisterRenderFunctionForWidget<WidgetTest>([](const std::shared_ptr<WidgetTest>& widget) {});
    }, "");
}