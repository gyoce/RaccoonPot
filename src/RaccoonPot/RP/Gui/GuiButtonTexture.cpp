#include "RP/Gui/GuiButtonTexture.hpp"

namespace RP
{

GuiButtonTexture::GuiButtonTexture(std::function<void()> callback, SDL_Texture* texture)
    : GuiButton(std::move(callback)), texture(texture) {  }

void GuiButtonTexture::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect = { Position.x, Position.y, Width, Height };
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

} // namespace RP