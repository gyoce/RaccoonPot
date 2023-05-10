#include "RP/Gui/GuiWidget.hpp"

#include <stack>
#include <cmath>

namespace RP
{

void GuiWidget::AddChild(const GuiWidgetPtr& widget) {
    Children.push_back(widget);
    widget->Parent = this;
    if (widget->horizontalAnchor != HorizontalAnchor::None || widget->verticalAnchor != VerticalAnchor::None) {
        UpdateChildrenPosition();
    }
}

void GuiWidget::SetPosition(const int x, const int y) {
    Position.x = x;
    Position.y = y;
}

void GuiWidget::SetSize(const int width, const int height) {
    const float widthFactor = static_cast<float>(width) / static_cast<float>(Width);
    const float heightFactor = static_cast<float>(height) / static_cast<float>(Height);
    Width = width;
    Height = height;
    UpdateChildrenPosition();
    UpdateChildrenSize(widthFactor, heightFactor);
}

void GuiWidget::SetAnchor(const HorizontalAnchor horizontalAnchor, const VerticalAnchor verticalAnchor) {
    this->horizontalAnchor = horizontalAnchor;
    this->verticalAnchor = verticalAnchor;
}

void GuiWidget::Draw(SDL_Renderer* renderer) {
    // Do nothing
}

void GuiWidget::UpdateChildrenPosition() const {
    const int numberOfChildren = static_cast<int>(Children.size());
    int fullHeight{};
    for (const GuiWidgetPtr& child : Children) {
        fullHeight += child->Height;
    }
    for (int indexOfChild = 0; indexOfChild < numberOfChildren; indexOfChild++) {
        const GuiWidgetPtr& child = Children[indexOfChild];
        switch (child->horizontalAnchor) {
        case HorizontalAnchor::Center:
            child->Position.x = this->Position.x + (this->Width / 2) - (child->Width / 2);
            break;
        }

        switch (child->verticalAnchor) {
        case VerticalAnchor::Center:
            const int height = getCorrectiveHeight(indexOfChild);
            child->Position.y = this->Position.y + (this->Height / 2) - (fullHeight / 2) + height;
            break;
        }
    }
    CallUpdatePositionForChildren();
}

void GuiWidget::UpdateChildrenSize(const float widthFactor, const float heightFactor) const {
    for (const GuiWidgetPtr& widget : Children) {
        const int width = static_cast<int>(std::round(widthFactor * static_cast<float>(widget->Width)));
        const int height = static_cast<int>(std::round(heightFactor * static_cast<float>(widget->Height)));
        widget->SetSize(width, height);
    }
}

void GuiWidget::CallUpdatePositionForChildren() const {
    if (Children.empty()) {
        return;
    }

    std::stack<GuiWidgetPtr> stackOfWidgets{};
    stackOfWidgets.push(Children[0]);
    while (!stackOfWidgets.empty()) {
        const GuiWidgetPtr widget = stackOfWidgets.top();
        stackOfWidgets.pop();
        widget->UpdateChildrenPosition();
        for (const GuiWidgetPtr& subWidget : widget->Children) {
            stackOfWidgets.push(subWidget);
        }
    }
}

int GuiWidget::getCorrectiveHeight(const int indexOfChild) const {
    if (indexOfChild == 0) {
        return 0;
    }
    int child = 0;
    int height = 0;
    while (child < indexOfChild) {
        height += Children[child]->Height;
        child++;
    }
    return height;
}

} // namespace RP