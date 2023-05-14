#include "RP/Gui/GuiButtonTextureText.hpp"

#include "RP/Gui/GuiText.hpp"

namespace RP
{

GuiButtonTextureText::GuiButtonTextureText(const std::function<void()>& callback, SDL_Texture* texture, const std::string& text, const FontPtr& font)
    : GuiButtonTexture(callback, texture) {
    guiText = std::make_shared<GuiText>(text, font);
    guiText->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    GuiWidget::AddChild(guiText);
}

void GuiButtonTextureText::SetSize(const int width, const int height) {
    GuiWidget::SetSize(width, height);
    guiText->SetSize(width, height);
}

} // namespace PR