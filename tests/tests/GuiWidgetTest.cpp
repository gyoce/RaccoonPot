#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class GuiWidgetTest : public testing::Test {
protected:
    void SetUp() override {
        panel = std::make_shared<RP::GuiWidget>();
        panel->Width = 1280;
        panel->Height = 720;
    }
    RP::GuiWidgetPtr panel;
};

TEST_F(GuiWidgetTest, CenterOneObject) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 100);
    button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    RP_EXPECT_EQ(button->Position, 590, 310, 0);
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

    RP_EXPECT_EQ(button1->Position, 590, 248, 0);
    RP_EXPECT_EQ(button2->Position, 603, 348, 0);
    RP_EXPECT_EQ(button3->Position, 615, 423, 0);
}

TEST_F(GuiWidgetTest, RepositioningChildrenWhenResizeWidget) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 100);
    button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    panel->SetSize(1920, 1080);
    RP_EXPECT_EQ(button->Position, 910, 490, 0);
}

TEST_F(GuiWidgetTest, ResizeChildrenWhenResizeWidget) {
    const RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 25);
    panel->AddChild(button);
    panel->SetSize(1920, 1080);
    EXPECT_EQ(button->Width, 150); EXPECT_EQ(button->Height, 38);
    panel->SetSize(1280, 720);
    EXPECT_EQ(button->Width, 100); EXPECT_EQ(button->Height, 25);
}