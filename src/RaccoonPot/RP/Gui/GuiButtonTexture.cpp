#include "RP/Gui/GuiButtonTexture.hpp"

namespace RP
{

void GuiButtonTexture::SetTexture(SDL_Texture* texture) {
    this->texture = texture;
}

void GuiButtonTexture::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect = { position.x, position.y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

} // namespace RP