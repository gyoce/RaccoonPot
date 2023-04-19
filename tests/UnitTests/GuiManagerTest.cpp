#include <gtest/gtest.h>

#include <CommonTypes.hpp>

#include <RP/RP.hpp>

using namespace RP;

class GuiManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        eventManager = std::make_shared<EventManager>();
        guiManager.RegisterEventManager(eventManager);
    }

    static void DrawWidget(std::shared_ptr<WidgetTest> widget) {
        widget->CallRenderFunction = true;
    }
    
    std::shared_ptr<EventManager> eventManager = nullptr;
    GuiManager guiManager{};
};

TEST_F(GuiManagerTest, CallRenderFunction) {
    guiManager.RegisterRenderFunctionForWidget<WidgetTest>([this](const std::shared_ptr<WidgetTest>& widget) { DrawWidget(widget); });
    std::shared_ptr<WidgetTest> widget = guiManager.CreateWidget<WidgetTest>();
    guiManager.Render();
    EXPECT_TRUE(widget->CallRenderFunction);
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