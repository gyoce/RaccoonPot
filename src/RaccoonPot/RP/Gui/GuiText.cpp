#include "RP/Gui/GuiText.hpp"

#include "RP/Core/Resources/Font.hpp"

namespace RP
{

GuiText::GuiText(std::string text, const FontPtr& font)
    : text(std::move(text)) {
    textTexture = font->GetTextTextureForText(this->text);
}

void GuiText::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect = { position.x, position.y, width, height };
    SDL_RenderCopy(renderer, textTexture, nullptr, &rect);
}


} // namespace RP