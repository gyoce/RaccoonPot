#include <gtest/gtest.h>

#include <CommonTypes.hpp>

using namespace RP;

class GuiWidgetTest : public ::testing::Test {
protected:
    void SetUp() override {
        panel = std::make_shared<GuiWidget>();
        panel->SetPosition(0, 0);
        panel->Width = 1280;
        panel->Height = 720;
    }
    GuiWidgetPtr panel;
};

TEST_F(GuiWidgetTest, CenterOneObject) {
    GuiButtonPtr button = std::make_shared<GuiButton>(nullptr);
    button->Width = 100; button->Height = 100;
    button->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    panel->AddChild(button);
    EXPECT_EQ(button->Position.x, 590); EXPECT_EQ(button->Position.y, 310);
}

TEST_F(GuiWidgetTest, CenterMultipleObjectsInColumn) {
    GuiButtonPtr button1 = std::make_shared<GuiButton>(nullptr);
    button1->Width = 100; button1->Height = 100;
    button1->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    GuiButtonPtr button2 = std::make_shared<GuiButton>(nullptr);
    button2->Width = 75; button2->Height = 75;
    button2->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    GuiButtonPtr button3 = std::make_shared<GuiButton>(nullptr);
    button3->Width = 50; button3->Height = 50;
    button3->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    
    panel->AddChild(button1);
    panel->AddChild(button2);
    panel->AddChild(button3);

    EXPECT_EQ(button1->Position.x, 590); EXPECT_EQ(button1->Position.y, 248);
    EXPECT_EQ(button2->Position.x, 603); EXPECT_EQ(button2->Position.y, 348);
    EXPECT_EQ(button3->Position.x, 615); EXPECT_EQ(button3->Position.y, 423);
}