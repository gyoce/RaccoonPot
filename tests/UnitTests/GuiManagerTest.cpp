#include <gtest/gtest.h>

#include <CommonTypes.hpp>

using namespace RP;

class GuiManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        eventManager = std::make_shared<EventManager>();
        guiManager = std::make_shared<GuiManager>();
        guiManager->RegisterEventManager(eventManager);
        guiManager->RegisterClickEvent(1);
        guiManager->RegisterWindowResizeEvent(2);
    }
    
    EventManagerPtr eventManager = nullptr;
    GuiManagerPtr guiManager = nullptr;
};

TEST_F(GuiManagerTest, CallRenderFunction) {
    std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    EXPECT_FALSE(widget->CallDrawFunction);
    guiManager->Render(nullptr);
    EXPECT_TRUE(widget->CallDrawFunction);
}

TEST_F(GuiManagerTest, CallConstructor) {
    std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>(10);
    EXPECT_TRUE(widget->ValueByConstructor == 10);
}

TEST_F(GuiManagerTest, CallClickEvent) {
    std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    widget->Position.x = 100; widget->Position.y = 100; widget->Width = 10; widget->Height = 10;
    eventManager->Dispatch<void(int, int)>(1, 10, 10); // Click missed
    EXPECT_FALSE(widget->CallClickFunction);
    eventManager->Dispatch<void(int, int)>(1, 101, 101); // Click inside
    EXPECT_TRUE(widget->CallClickFunction);
}

TEST_F(GuiManagerTest, WidgetCreateWithAParent) {
    std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    EXPECT_TRUE(widget->Parent != nullptr);
}

TEST_F(GuiManagerTest, ResizeWindow) {
    std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    EXPECT_TRUE(widget->Parent->Width == 1280 && widget->Parent->Height == 720);
    eventManager->Dispatch<void(int, int)>(2, 1920, 1080);
    EXPECT_TRUE(widget->Parent->Width == 1920 && widget->Parent->Height == 1080);
}

#ifndef NDEBUG

TEST(GuiManagerDeath, RegisterClickEventBeforeRegisterEventManager) {
    GuiManager guiManager{};
    ASSERT_DEATH({
        guiManager.RegisterClickEvent(1);
    }, "");
}

#endif // NDEBUG