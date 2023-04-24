#include "GuiButtonTexture.hpp"

#include "../SdlGuiRenderSystem.hpp"

GuiButtonTexture::GuiButtonTexture(std::function<void()> callback)
    : callback(std::move(callback)) {  }

GuiButtonTexture::~GuiButtonTexture() {
    if (Texture != nullptr) { SDL_DestroyTexture(Texture); }
}

void GuiButtonTexture::Click() {
    callback();
}

void GuiButtonTexture::Draw(const RP::IGuiRenderSystemPtr& renderSystem) {
    const std::shared_ptr<SdlGuiRenderSystem> sdlRenderSystem = std::static_pointer_cast<SdlGuiRenderSystem>(renderSystem);
    const SDL_Rect rect = { Position.x, Position.y, Width, Height };
    sdlRenderSystem->RenderTexture(Texture, rect);
}