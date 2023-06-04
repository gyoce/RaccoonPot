#include "RP/Gui/GuiButtonText.hpp"

#include "RP/Gui/GuiText.hpp"

namespace RP
{

GuiButtonText::GuiButtonText(const GuiButtonText& guiButtonText) : GuiButton(guiButtonText) {
    paddingWithText = guiButtonText.paddingWithText;
}

void GuiButtonText::SetPosition(const int x, const int y) {
    GuiWidget::SetPosition(x, y);
    if (guiText != nullptr) {
        guiText->SetPosition(this->position.x + paddingWithText, this->position.y + paddingWithText);
    }
}

void GuiButtonText::SetPadding(const int padding) {
    this->paddingWithText = padding;
}

void GuiButtonText::SetText(const std::string& text, const FontPtr& font) {
    if (guiText != nullptr) {
        std::erase(Children, guiText);
        delete guiText;
    }
    guiText = new GuiText(text, font);
    guiText->SetSize(width - 2 * paddingWithText, height - 2 * paddingWithText);
    guiText->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    GuiWidget::AddChild(guiText);
}

GuiText* GuiButtonText::GetGuiText() const {
    return guiText;
}

} // namespace RP