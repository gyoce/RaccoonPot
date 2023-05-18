#include "RP/Gui/GuiButtonText.hpp"

#include "RP/Gui/GuiText.hpp"

namespace RP
{

GuiButtonText::GuiButtonText(std::function<void()> callback, const std::string& text, const FontPtr& font)
    : GuiButton(std::move(callback)) {
    guiText = std::make_shared<GuiText>(text, font);
    guiText->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    GuiWidget::AddChild(guiText);
}

void GuiButtonText::SetSize(const int width, const int height) {
    GuiWidget::SetSize(width, height);
    guiText->SetSize(width, height);
    guiText->SetPosition(this->position.x + paddingWithText, this->position.y + paddingWithText);
}

void GuiButtonText::SetPosition(const int x, const int y) {
    GuiWidget::SetPosition(x, y);
    guiText->SetPosition(this->position.x + paddingWithText, this->position.y + paddingWithText);
}

void GuiButtonText::SetPadding(const int padding) {
    this->paddingWithText = padding;
    guiText->SetSize(width - 2 * paddingWithText, height - 2 * paddingWithText);
    guiText->SetPosition(this->position.x + paddingWithText, this->position.y + paddingWithText);
}

GuiTextPtr& GuiButtonText::GetGuiText() {
    return guiText;
}

} // namespace RP