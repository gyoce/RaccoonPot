#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class GuiManagerTest : public testing::Test {
protected:
    void SetUp() override {
        eventManager = std::make_shared<RP::EventManager>();
        guiManager = std::make_shared<RP::GuiManager>();
        guiManager->RegisterEventManager(eventManager);
        guiManager->RegisterClickEvent(1);
        guiManager->RegisterWindowResizeEvent(2);
        guiManager->RegisterMouseMoveEvent(3);
    }
    
    RP::EventManagerPtr eventManager = nullptr;
    RP::GuiManagerPtr guiManager = nullptr;
};

TEST_F(GuiManagerTest, CallRenderFunction) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    guiManager->AddToMainPanel(widget);
    EXPECT_FALSE(widget->CallDrawFunction);
    guiManager->Render(nullptr);
    EXPECT_TRUE(widget->CallDrawFunction);
}

TEST_F(GuiManagerTest, CallConstructor) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>(10);
    EXPECT_EQ(widget->ValueByConstructor, 10);
}

TEST_F(GuiManagerTest, CallClickEvent) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    widget->SetPosition(100, 100);
    widget->SetSize(10, 10);
    guiManager->AddToMainPanel(widget);
    eventManager->Dispatch<void(int, int)>(1, 10, 10); // Click missed
    EXPECT_FALSE(widget->CallClickFunction);
    eventManager->Dispatch<void(int, int)>(1, 101, 101); // Click inside
    EXPECT_TRUE(widget->CallClickFunction);
}

TEST_F(GuiManagerTest, WidgetCreateWithAParent) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    guiManager->AddToMainPanel(widget);
    EXPECT_TRUE(widget->Parent != nullptr);
}

TEST_F(GuiManagerTest, ResizeWindow) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    guiManager->AddToMainPanel(widget);
    eventManager->Dispatch<void(int, int)>(2, 1920, 1080);
    RP_EXPECT_EQ_SIZE(widget->Parent->GetWidth(), widget->Parent->GetHeight(), 1920, 1080);
}

TEST_F(GuiManagerTest, MouseMoveWithHoverableWidget) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    widget->SetPosition(10, 10);
    widget->SetSize(10, 10);
    widget->SetHoverable(true);
    guiManager->AddToMainPanel(widget);
    eventManager->Dispatch<void(int, int)>(3, 9, 9); // Outside
    EXPECT_FALSE(widget->GetHover());
    eventManager->Dispatch<void(int, int)>(3, 11, 11); // Inside
    EXPECT_TRUE(widget->GetHover());
}

TEST_F(GuiManagerTest, MouseMoveWithNonHoverableWidget) {
    const std::shared_ptr<WidgetTest> widget = guiManager->CreateWidget<WidgetTest>();
    widget->SetPosition(10, 10);
    widget->SetSize(10, 10);
    guiManager->AddToMainPanel(widget);
    eventManager->Dispatch<void(int, int)>(3, 11, 11); // Inside
    EXPECT_FALSE(widget->GetHover());
}

#ifndef NDEBUG

TEST(GuiManagerDeath, RegisterClickEventBeforeRegisterEventManager) {
    const RP::GuiManager guiManager{};
    ASSERT_DEATH({
        guiManager.RegisterClickEvent(1);
    }, "");
}

#endif // NDEBUG