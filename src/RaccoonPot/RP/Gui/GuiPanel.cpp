#include "RP/Gui/GuiPanel.hpp"

namespace RP
{

void GuiPanel::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect = { position.x, position.y, width, height };
    SDL_Color color;
    SDL_GetRenderDrawColor(renderer, &color.r, &color.g, &color.b, &color.a);
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void GuiPanel::SetBackgroundColor(const SDL_Color color) {
    backgroundColor = color;
}

} // namespace RP