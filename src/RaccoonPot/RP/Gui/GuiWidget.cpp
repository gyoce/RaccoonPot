#include "RP/Gui/GuiWidget.hpp"

using namespace RP;

void GuiWidget::AddChild(const GuiWidgetPtr& widget) {
    Children.push_back(widget);
    widget->Parent = this;
}