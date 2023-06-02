#include <gtest/gtest.h>

#include <CommonTypes.hpp>

class GuiWidgetTest : public testing::Test {
protected:
    ~GuiWidgetTest() override {
        delete mainPanel;
    }

    void SetUp() override {
        mainPanel = new RP::GuiPanel();
        mainPanel->SetSize(1280, 720);
    }

    RP::GuiPanel* mainPanel = nullptr;
};

TEST_F(GuiWidgetTest, CenterOneObject) {
    auto* panel = new RP::GuiPanel();
    panel->SetSize(100, 100);
    panel->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 590, 310, 0);
}

TEST_F(GuiWidgetTest, CenterMultipleObjectsInColumn) {
    mainPanel->SetPaddingBetweenChildren(10);
    auto* panel1 = new RP::GuiPanel();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    auto* panel2 = new RP::GuiPanel();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    auto* panel3 = new RP::GuiPanel();
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
    auto* panel1 = new RP::GuiPanel();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    auto* panel2 = new RP::GuiPanel();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    auto* panel3 = new RP::GuiPanel();
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
    auto* panel1 = new RP::GuiPanel();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Left, RP::VerticalAnchor::Center);
    auto* panel2 = new RP::GuiPanel();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Right, RP::VerticalAnchor::Center);

    mainPanel->AddChild(panel1);
    mainPanel->AddChild(panel2);

    RP_EXPECT_EQ_POSITION(panel1->GetPosition(), 0, 310, 0);
    RP_EXPECT_EQ_POSITION(panel2->GetPosition(), 1205, 323, 0);
}

TEST_F(GuiWidgetTest, MultipleObjectsTopAndBottomWithCenterHorizontally) {
    auto* panel1 = new RP::GuiPanel();
    panel1->SetSize(100, 100);
    panel1->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Top);
    auto* panel2 = new RP::GuiPanel();
    panel2->SetSize(75, 75);
    panel2->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Bottom);

    mainPanel->AddChild(panel1);
    mainPanel->AddChild(panel2);

    RP_EXPECT_EQ_POSITION(panel1->GetPosition(), 590, 0, 0);
    RP_EXPECT_EQ_POSITION(panel2->GetPosition(), 603, 645, 0);
}

TEST_F(GuiWidgetTest, RepositioningChildrenWhenResizeWidget) {
    auto* panel = new RP::GuiPanel();
    panel->SetSize(100, 100);
    panel->SetAnchor(RP::HorizontalAnchor::Center, RP::VerticalAnchor::Center);
    mainPanel->AddChild(panel);
    mainPanel->SetSize(1920, 1080);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 910, 490, 0);
}

TEST_F(GuiWidgetTest, ResizeChildrenWhenResizeWidget) {
    auto* panel = new RP::GuiPanel();
    panel->SetSize(100, 25);
    mainPanel->AddChild(panel);
    mainPanel->SetSize(1920, 1080);
    RP_EXPECT_EQ_SIZE(panel->GetWidth(), panel->GetHeight(), 150, 38);
    mainPanel->SetSize(1280, 720);
    RP_EXPECT_EQ_SIZE(panel->GetWidth(), panel->GetHeight(), 100, 25);
}

TEST_F(GuiWidgetTest, AnchorLeftOneElement) {
    auto* panel = new RP::GuiPanel();
    panel->SetPosition(100, 100);
    panel->SetSize(100, 720);
    panel->SetHorizontalAnchor(RP::HorizontalAnchor::Left);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 0, 0, 0);
}

TEST_F(GuiWidgetTest, AnchorRightOneElement) {
    auto* panel = new RP::GuiPanel();
    panel->SetPosition(100, 100);
    panel->SetSize(100, 720);
    panel->SetHorizontalAnchor(RP::HorizontalAnchor::Right);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 1180, 0, 0);
}

TEST_F(GuiWidgetTest, AnchorBottomOneElement) {
    auto* panel = new RP::GuiPanel();
    panel->SetPosition(100, 100);
    panel->SetSize(1280, 100);
    panel->SetVerticalAnchor(RP::VerticalAnchor::Bottom);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 0, 620, 0);
}

TEST_F(GuiWidgetTest, AnchorTopOneElement) {
    auto* panel = new RP::GuiPanel();
    panel->SetPosition(100, 100);
    panel->SetSize(1280, 100);
    panel->SetVerticalAnchor(RP::VerticalAnchor::Top);
    mainPanel->AddChild(panel);
    RP_EXPECT_EQ_POSITION(panel->GetPosition(), 0, 0, 0);
}

TEST_F(GuiWidgetTest, GuiButtonTextWithPadding) {
    const RP::FontPtr font = std::make_shared<RP::Font>(nullptr, nullptr);
    auto* buttonText = new RP::GuiButtonText();
    buttonText->SetText("", font);
    buttonText->SetPadding(10);
    buttonText->SetSize(100, 100);
    buttonText->SetPosition(100, 200);
    RP_EXPECT_EQ_POSITION(buttonText->GetGuiText()->GetPosition(), 110, 210, 0);
    delete buttonText;
}