#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class GuiWidgetTest : public testing::Test {
protected:
    void SetUp() override {
        panel = std::make_shared<RP::GuiPanel>();
        panel->SetSize(1280, 720);
    }
    RP::GuiPanelPtr panel;
};

TEST_F(GuiWidgetTest, CenterOneObject) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 100);
    button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    RP_EXPECT_EQ_POSITION(button->GetPosition(), 590, 310, 0);
}

TEST_F(GuiWidgetTest, CenterMultipleObjectsInColumn) {
    const RP::GuiButtonPtr button1 = std::make_shared<RP::GuiButton>(nullptr);
    button1->SetSize(100, 100);
    button1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    const RP::GuiButtonPtr button2 = std::make_shared<RP::GuiButton>(nullptr);
    button2->SetSize(75, 75);
    button2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    const RP::GuiButtonPtr button3 = std::make_shared<RP::GuiButton>(nullptr);
    button3->SetSize(50, 50);
    button3->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    
    panel->AddChild(button1);
    panel->AddChild(button2);
    panel->AddChild(button3);

    RP_EXPECT_EQ_POSITION(button1->GetPosition(), 590, 248, 0);
    RP_EXPECT_EQ_POSITION(button2->GetPosition(), 603, 348, 0);
    RP_EXPECT_EQ_POSITION(button3->GetPosition(), 615, 423, 0);
}

TEST_F(GuiWidgetTest, RepositioningChildrenWhenResizeWidget) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 100);
    button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    panel->SetSize(1920, 1080);
    RP_EXPECT_EQ_POSITION(button->GetPosition(), 910, 490, 0);
}

TEST_F(GuiWidgetTest, ResizeChildrenWhenResizeWidget) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 25);
    panel->AddChild(button);
    panel->SetSize(1920, 1080);
    RP_EXPECT_EQ_SIZE(button->GetWidth(), button->GetHeight(), 150, 38);
    panel->SetSize(1280, 720);
    RP_EXPECT_EQ_SIZE(button->GetWidth(), button->GetHeight(), 100, 25);
}

TEST_F(GuiWidgetTest, AnchorLeftOneElement) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 80);
    button->SetAnchor(RP::HorizontalAnchor::Left, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    RP_EXPECT_EQ_POSITION(button->GetPosition(), 0, 320, 0);
}

TEST_F(GuiWidgetTest, AnchorRightOneElement) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 80);
    button->SetAnchor(RP::HorizontalAnchor::Right, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    RP_EXPECT_EQ_POSITION(button->GetPosition(), 1180, 320, 0);
}