#include <utility>

#include "RP/Gui/GuiButton.hpp"

namespace RP
{

GuiButton::GuiButton(const GuiButton& guiButton) : GuiWidget(guiButton) {
    backgroundColor = guiButton.backgroundColor;
}

void GuiButton::Click() {
    callback();
}

void GuiButton::Draw(SDL_Renderer* renderer) {
    const SDL_Rect rect{ position.x, position.y, width, height };
    if (hover) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    }
    SDL_RenderFillRect(renderer, &rect);
}

void GuiButton::SetBackgroundColor(const SDL_Color color) {
    backgroundColor = color;
}

void GuiButton::SetCallback(std::function<void()> callback) {
    this->callback = std::move(callback);
}

} // namespace RP