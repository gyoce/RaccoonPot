#include "RP/Gui/GuiWidget.hpp"

#include <stack>
#include <cmath>
#include <limits>

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
    position.x = x;
    position.y = y;
}

void GuiWidget::SetSize(const int width, const int height) {
    float widthFactor = static_cast<float>(width) / static_cast<float>(this->width);
    float heightFactor = static_cast<float>(height) / static_cast<float>(this->height);
    widthFactor = widthFactor == std::numeric_limits<float>::infinity() ? 1.0f : widthFactor;
    heightFactor = heightFactor == std::numeric_limits<float>::infinity() ? 1.0f : heightFactor;
    this->width = width;
    this->height = height;
    UpdateChildrenPosition();
    UpdateChildrenSize(widthFactor, heightFactor);
}

void GuiWidget::SetAnchor(const HorizontalAnchor horizontalAnchor, const VerticalAnchor verticalAnchor) {
    this->horizontalAnchor = horizontalAnchor;
    this->verticalAnchor = verticalAnchor;
}

Vector3Int& GuiWidget::GetPosition() {
    return position;
}

int GuiWidget::GetHeight() {
    return height;
}

int GuiWidget::GetWidth() {
    return width;
}

void GuiWidget::UpdateChildrenPosition() const {
    const int numberOfChildren = static_cast<int>(Children.size());
    int fullHeight{};
    for (const GuiWidgetPtr& child : Children) {
        fullHeight += child->height;
    }
    for (int indexOfChild = 0; indexOfChild < numberOfChildren; indexOfChild++) {
        const GuiWidgetPtr& child = Children[indexOfChild];
        int newX{}, newY{};
        switch (child->horizontalAnchor) {
        case HorizontalAnchor::Center:
            newX = this->position.x + (this->width / 2) - (child->width / 2);
            break;
        case HorizontalAnchor::Left:
            newX = this->position.x;
            break;
        case HorizontalAnchor::Right:
            newX = this->position.x + this->width - child->width;
            break;
        }

        switch (child->verticalAnchor) {
        case VerticalAnchor::Center:
            const int height = getCorrectiveHeight(indexOfChild);
            newY = this->position.y + (this->height / 2) - (fullHeight / 2) + height;
            break;
        }

        child->SetPosition(newX, newY);
    }
    CallUpdatePositionForChildren();
}

void GuiWidget::UpdateChildrenSize(const float widthFactor, const float heightFactor) const {
    for (const GuiWidgetPtr& widget : Children) {
        const int width = static_cast<int>(std::round(widthFactor * static_cast<float>(widget->width)));
        const int height = static_cast<int>(std::round(heightFactor * static_cast<float>(widget->height)));
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
        height += Children[child]->height;
        child++;
    }
    return height;
}

} // namespace RP