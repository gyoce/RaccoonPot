#include "GuiButtonTexture.hpp"

GuiButtonTexture::~GuiButtonTexture() {
    if (Texture != nullptr) { SDL_DestroyTexture(Texture); }
}

void GuiButtonTexture::Click() {
    RP::Log("Click on button Texture");
}