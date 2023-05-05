#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class GuiWidgetTest : public ::testing::Test {
protected:
    void SetUp() override {
        panel = std::make_shared<RP::GuiWidget>();
        panel->SetPosition(0, 0);
        panel->Width = 1280;
        panel->Height = 720;
    }
    RP::GuiWidgetPtr panel;
};

TEST_F(GuiWidgetTest, CenterOneObject) {
    RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 100);
    button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    EXPECT_EQ(button->Position.x, 590); EXPECT_EQ(button->Position.y, 310);
}

TEST_F(GuiWidgetTest, CenterMultipleObjectsInColumn) {
    RP::GuiButtonPtr button1 = std::make_shared<RP::GuiButton>(nullptr);
    button1->SetSize(100, 100);
    button1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    RP::GuiButtonPtr button2 = std::make_shared<RP::GuiButton>(nullptr);
    button2->SetSize(75, 75);
    button2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    RP::GuiButtonPtr button3 = std::make_shared<RP::GuiButton>(nullptr);
    button3->SetSize(50, 50);
    button3->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    
    panel->AddChild(button1);
    panel->AddChild(button2);
    panel->AddChild(button3);

    EXPECT_EQ(button1->Position.x, 590); EXPECT_EQ(button1->Position.y, 248);
    EXPECT_EQ(button2->Position.x, 603); EXPECT_EQ(button2->Position.y, 348);
    EXPECT_EQ(button3->Position.x, 615); EXPECT_EQ(button3->Position.y, 423);
}

TEST_F(GuiWidgetTest, ResizeChildrenWhenResizeWidget) {
    RP::GuiButtonPtr button = std::make_shared<RP::GuiButton>(nullptr);
    button->SetSize(100, 100);
    button->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    panel->AddChild(button);
    panel->SetSize(1920, 1080);
    EXPECT_EQ(button->Position.x, 910); EXPECT_EQ(button->Position.y, 490);
}