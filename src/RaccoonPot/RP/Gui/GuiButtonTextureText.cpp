#include "RP/Gui/GuiButtonTextureText.hpp"

#include "RP/Gui/GuiText.hpp"

namespace RP
{

GuiButtonTextureText::GuiButtonTextureText(const std::function<void()>& callback, SDL_Texture* texture, const std::string& text, const FontPtr& font)
    : GuiButtonTexture(callback, texture) {
    guiText = std::make_shared<GuiText>(text, font);
    guiText->SetAnchor(HorizontalAnchor::Center, VerticalAnchor::Center);
    AddChild(guiText);
}

void GuiButtonTextureText::Draw(SDL_Renderer* renderer) {
    GuiButtonTexture::Draw(renderer);
}

void GuiButtonTextureText::SetSize(const int width, const int height) {
    guiText->Width = width;
    guiText->Height = height;
    GuiWidget::SetSize(width, height);
}

} // namespace PR