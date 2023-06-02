#include "RP/Gui/GuiButtonTextureText.hpp"

#include "RP/Gui/GuiText.hpp"

namespace RP
{

void GuiButtonTextureText::SetSize(const int width, const int height) {
    GuiWidget::SetSize(width, height);
    guiText->SetSize(width, height);
}

void GuiButtonTextureText::SetText(const std::string& text, const FontPtr& font) {
    if (guiText != nullptr) {
        std::erase(Children, guiText);
        delete guiText;
        guiText = nullptr;
    }
    guiText = new GuiText(text, font);
    guiText->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    GuiWidget::AddChild(guiText);
}

} // namespace PR