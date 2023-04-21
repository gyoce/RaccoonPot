#include "GuiButtonTexture.hpp"

GuiButtonTexture::GuiButtonTexture(std::function<void()> callback)
    : callback(std::move(callback)) {  }

GuiButtonTexture::~GuiButtonTexture() {
    if (Texture != nullptr) { SDL_DestroyTexture(Texture); }
}

void GuiButtonTexture::Click() {
    callback();
}