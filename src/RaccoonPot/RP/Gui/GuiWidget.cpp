#include "RP/Gui/GuiWidget.hpp"

namespace RP
{

void GuiWidget::AddChild(const GuiWidgetPtr& widget) {
    Children.push_back(widget);
    widget->Parent = this;
    if (widget->horizontalAnchor != HorizontalAnchor::None || widget->verticalAnchor != VerticalAnchor::None) {
        UpdateChildrenPositions();
    }
}

void GuiWidget::SetPosition(const int x, const int y) {
    Position.x = x;
    Position.y = y;
}

void GuiWidget::SetSize(const int width, const int height) {
    Width = width;
    Height = height;
    UpdateChildrenPositions();
}

void GuiWidget::SetAnchor(const HorizontalAnchor horizontalAnchor, const VerticalAnchor verticalAnchor) {
    this->horizontalAnchor = horizontalAnchor;
    this->verticalAnchor = verticalAnchor;
}

void GuiWidget::Draw(SDL_Renderer* renderer) {
    // Do nothing
}

void GuiWidget::UpdateChildrenPositions() const {
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

}