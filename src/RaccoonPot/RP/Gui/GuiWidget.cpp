#include "RP/Gui/GuiWidget.hpp"

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

void GuiWidget::SetHorizontalAnchor(const HorizontalAnchor anchor) {
    this->horizontalAnchor = anchor;
}

void GuiWidget::SetVerticalAnchor(const VerticalAnchor anchor) {
    this->verticalAnchor = anchor;
}

void GuiWidget::SetAlignItems(const AlignItems alignItems) {
    this->alignItems = alignItems;
}

void GuiWidget::SetPaddingBetweenChildren(const int padding) {
    this->paddingBetweenChildren = padding;
}

void GuiWidget::SetHoverable(const bool hoverable) {
    this->hoverable = hoverable;
}

void GuiWidget::SetHover(const bool hover) {
    this->hover = hover;
}

Vector3Int& GuiWidget::GetPosition() {
    return position;
}

int GuiWidget::GetHeight() {
    return height;
}

bool GuiWidget::IsHoverable() {
    return hoverable;
}

int GuiWidget::GetWidth() {
    return width;
}

void GuiWidget::UpdateChildrenPosition() const {
    const int numberOfChildren = static_cast<int>(Children.size());
    int fullHeight{}, fullWidth{};
    for (const GuiWidgetPtr& child : Children) {
        fullHeight += child->height + paddingBetweenChildren;
        fullWidth += child->width + paddingBetweenChildren;
    }
    fullHeight -= paddingBetweenChildren; fullWidth -= paddingBetweenChildren;
    for (int indexOfChild = 0; indexOfChild < numberOfChildren; indexOfChild++) {
        const GuiWidgetPtr& child = Children[indexOfChild];
        int newX{}, newY{};
        const int width = getCorrectiveWidth(indexOfChild);
        switch (child->horizontalAnchor) {
        case HorizontalAnchor::Center:
            if (alignItems == AlignItems::Row && child->verticalAnchor == VerticalAnchor::Center) {
                newX = this->position.x + (this->width / 2) - (fullWidth / 2) + width;
            } else {
                newX = this->position.x + (this->width / 2) - (child->width / 2);
            }
            break;
        case HorizontalAnchor::Right:
            newX = this->position.x + this->width - child->width;
            break;
        case HorizontalAnchor::None:
        case HorizontalAnchor::Left:
            newX = this->position.x;
            break;
        }

        const int height = getCorrectiveHeight(indexOfChild);
        switch (child->verticalAnchor) {
        case VerticalAnchor::Center:
            if (alignItems == AlignItems::Column && child->horizontalAnchor == HorizontalAnchor::Center) {
                newY = this->position.y + (this->height / 2) - (fullHeight / 2) + height;
            } else {
                newY = this->position.y + (this->height / 2) - (child->height / 2);
            }
            break;
        case VerticalAnchor::Bottom:
            newY = this->position.y + this->height - child->height;
            break;
        case VerticalAnchor::None:
        case VerticalAnchor::Top:
            newY = this->position.y;
            break;
        }

        if (newX != child->position.x || newY != child->position.y) {
            child->SetPosition(newX, newY);
        }
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
    for (const GuiWidgetPtr& child : Children) {
        child->UpdateChildrenPosition();
    }
}

int GuiWidget::getCorrectiveHeight(const int indexOfChild) const {
    if (indexOfChild == 0) {
        return 0;
    }
    int child = 0;
    int height = 0;
    while (child < indexOfChild) {
        height += Children[child]->height + paddingBetweenChildren;
        child++;
    }
    return height;
}

int GuiWidget::getCorrectiveWidth(const int indexOfChild) const {
    if (indexOfChild == 0) {
        return 0;
    }
    int child = 0;
    int width = 0;
    while (child < indexOfChild) {
        width += Children[child]->width + paddingBetweenChildren;
        child++;
    }
    return width;
}

} // namespace RP