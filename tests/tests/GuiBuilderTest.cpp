#include <gtest/gtest.h>

#include <CommonTypes.hpp>

TEST(GuiBuilder, ShouldBuildCorrectly) {
    RP::GuiBuilder<WidgetTest> builder{};
    builder->SetHoverable(true);
    const WidgetTest* widget = builder.Build();
    EXPECT_TRUE(widget->GetHoverable());
    delete widget;
}

TEST(GuiBuilder, ShouldBuildMultipleObjectWithSameProperties) {
    RP::GuiBuilder<WidgetTest> builder{};
    builder->SetSize(100, 125);
    builder->SetPosition(50, 75);
    WidgetTest* widget = builder.Build();
    RP_EXPECT_EQ_SIZE(widget->GetWidth(), widget->GetHeight(), 100, 125);
    RP_EXPECT_EQ_POSITION(widget->GetPosition(), 50, 75, 0);
    delete widget;

    widget = builder.Build();
    RP_EXPECT_EQ_SIZE(widget->GetWidth(), widget->GetHeight(), 100, 125);
    RP_EXPECT_EQ_POSITION(widget->GetPosition(), 50, 75, 0);
    delete widget;
}

TEST(GuiBuilder, ShouldBuildMultipleObjectWithMultiplesPropertiesValues) {
    RP::GuiBuilder<WidgetTest> builder{};
    builder->SetSize(100, 125);
    builder->SetPosition(50, 75);
    WidgetTest* widget = builder.Build();
    RP_EXPECT_EQ_SIZE(widget->GetWidth(), widget->GetHeight(), 100, 125);
    RP_EXPECT_EQ_POSITION(widget->GetPosition(), 50, 75, 0);
    delete widget;

    builder->SetSize(150, 175);
    widget = builder.Build();
    RP_EXPECT_EQ_SIZE(widget->GetWidth(), widget->GetHeight(), 150, 175);
    RP_EXPECT_EQ_POSITION(widget->GetPosition(), 50, 75, 0);
    delete widget;
}