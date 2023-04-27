#include "RP/Gui/GuiWidget.hpp"

using namespace RP;

void GuiWidget::AddChild(const GuiWidgetPtr& widget) {
    Children.push_back(widget);
    widget->Parent = this;
}

void GuiWidget::SetPosition(const int x, const int y) {
    Position.x = x;
    Position.y = y;
}