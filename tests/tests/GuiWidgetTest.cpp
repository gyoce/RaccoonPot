#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class GuiWidgetTest : public testing::Test {
protected:
    void SetUp() override {
        mainPanel = std::make_shared<RP::GuiPanel>();
        mainPanel->SetSize(1280, 720);
    }
    RP::GuiPanelPtr mainPanel;
};

TEST_F(GuiWidgetTest, CenterOneObject) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetSize(100, 100);
    panel->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 590, 310, 0);
}

TEST_F(GuiWidgetTest, CenterMultipleObjectsInColumn) {
    mainPanel->SetPaddingBetweenChildren(10);
    const RP::GuiPanelPtr panel1 = std::make_shared<RP::GuiPanel>();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    const RP::GuiPanelPtr panel2 = std::make_shared<RP::GuiPanel>();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    const RP::GuiPanelPtr panel3 = std::make_shared<RP::GuiPanel>();
    panel3->SetSize(50, 50);
    panel3->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    
    mainPanel->AddChild(panel1);
    mainPanel->AddChild(panel2);
    mainPanel->AddChild(panel3);

    RP_EXPECT_EQ_POSITION(panel1->GetPosition(), 590, 238, 0);
    RP_EXPECT_EQ_POSITION(panel2->GetPosition(), 603, 348, 0);
    RP_EXPECT_EQ_POSITION(panel3->GetPosition(), 615, 433, 0);
}

TEST_F(GuiWidgetTest, CenterMultipleObjectsInRow) {
    mainPanel->SetPaddingBetweenChildren(10);
    mainPanel->SetAlignItems(RP::AlignItems::Row);
    const RP::GuiPanelPtr panel1 = std::make_shared<RP::GuiPanel>();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    const RP::GuiPanelPtr panel2 = std::make_shared<RP::GuiPanel>();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    const RP::GuiPanelPtr panel3 = std::make_shared<RP::GuiPanel>();
    panel3->SetSize(50, 50);
    panel3->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);

    mainPanel->AddChild(panel1);
    mainPanel->AddChild(panel2);
    mainPanel->AddChild(panel3);

    RP_EXPECT_EQ_POSITION(panel1->GetPosition(), 518, 310, 0);
    RP_EXPECT_EQ_POSITION(panel2->GetPosition(), 628, 323, 0);
    RP_EXPECT_EQ_POSITION(panel3->GetPosition(), 713, 335, 0);
}

TEST_F(GuiWidgetTest, MultipleObjectsLeftAndRightWithCenterVertically) {
    const RP::GuiPanelPtr panel1 = std::make_shared<RP::GuiPanel>();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Left, RP::VerticalAnchor::Center);
    const RP::GuiPanelPtr panel2 = std::make_shared<RP::GuiPanel>();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Right, RP::VerticalAnchor::Center);

    mainPanel->AddChild(panel1);
    mainPanel->AddChild(panel2);

    RP_EXPECT_EQ_POSITION(panel1->GetPosition(), 0, 310, 0);
    RP_EXPECT_EQ_POSITION(panel2->GetPosition(), 1205, 323, 0);
}

TEST_F(GuiWidgetTest, MultipleObjectsTopAndBottomWithCenterHorizontally) {
    const RP::GuiPanelPtr panel1 = std::make_shared<RP::GuiPanel>();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Top);
    const RP::GuiPanelPtr panel2 = std::make_shared<RP::GuiPanel>();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Bottom);

    mainPanel->AddChild(panel1);
    mainPanel->AddChild(panel2);

    RP_EXPECT_EQ_POSITION(panel1->GetPosition(), 590, 0, 0);
    RP_EXPECT_EQ_POSITION(panel2->GetPosition(), 603, 645, 0);
}

TEST_F(GuiWidgetTest, RepositioningChildrenWhenResizeWidget) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetSize(100, 100);
    panel->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    mainPanel->AddChild(panel);
    mainPanel->SetSize(1920, 1080);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 910, 490, 0);
}

TEST_F(GuiWidgetTest, ResizeChildrenWhenResizeWidget) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetSize(100, 25);
    mainPanel->AddChild(panel);
    mainPanel->SetSize(1920, 1080);
    RP_EXPECT_EQ_SIZE(panel->GetWidth(), panel->GetHeight(), 150, 38);
    mainPanel->SetSize(1280, 720);
    RP_EXPECT_EQ_SIZE(panel->GetWidth(), panel->GetHeight(), 100, 25);
}

TEST_F(GuiWidgetTest, AnchorLeftOneElement) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetPosition(100, 100);
    panel->SetSize(100, 720);
    panel->SetHorizontalAnchor(RP::HorizontalAnchor::Left);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 0, 0, 0);
}

TEST_F(GuiWidgetTest, AnchorRightOneElement) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetPosition(100, 100);
    panel->SetSize(100, 720);
    panel->SetHorizontalAnchor(RP::HorizontalAnchor::Right);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 1180, 0, 0);
}

TEST_F(GuiWidgetTest, AnchorBottomOneElement) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetPosition(100, 100);
    panel->SetSize(1280, 100);
    panel->SetVerticalAnchor(RP::VerticalAnchor::Bottom);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 0, 620, 0);
}

TEST_F(GuiWidgetTest, AnchorTopOneElement) {
    const RP::GuiPanelPtr panel = std::make_shared<RP::GuiPanel>();
    panel->SetPosition(100, 100);
    panel->SetSize(1280, 100);
    panel->SetVerticalAnchor(RP::VerticalAnchor::Top);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 0, 0, 0);
}

TEST_F(GuiWidgetTest, GuiButtonTextWithPadding) {
    const RP::FontPtr font = std::make_shared<RP::Font>(nullptr, nullptr);
    const RP::GuiButtonTextPtr buttonText = std::make_shared<RP::GuiButtonText>(nullptr, "", font);
    buttonText->SetPadding(10);
    buttonText->SetSize(100, 100);
    buttonText->SetPosition(100, 200);
    RP_EXPECT_EQ_POSITION(buttonText->GetGuiText()->GetPosition(), 110, 210, 0);
}