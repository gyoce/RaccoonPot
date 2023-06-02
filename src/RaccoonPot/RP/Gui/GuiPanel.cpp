#include "RP/Gui/GuiPanel.hpp"

namespace RP
{

GuiPanel::GuiPanel(const GuiPanel& guiPanel) : GuiWidget(guiPanel) {
    backgroundColor = guiPanel.backgroundColor;
}

void GuiPanel::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect = { position.x, position.y, width, height };
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderFillRect(renderer, &rect);
}

void GuiPanel::SetBackgroundColor(const SDL_Color color) {
    backgroundColor = color;
}

} // namespace RP