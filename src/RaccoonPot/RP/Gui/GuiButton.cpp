#include "RP/Gui/GuiButton.hpp"

namespace RP
{

GuiButton::GuiButton(std::function<void()> callback)
    : callback(std::move(callback)) {  }

void GuiButton::Click() {
    callback();
}

void GuiButton::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect{ Position.x, Position.y, Width, Height };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

} // namespace RP