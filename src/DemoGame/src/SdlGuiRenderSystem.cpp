#include "SdlGuiRenderSystem.hpp"

SdlGuiRenderSystem::SdlGuiRenderSystem(SDL_Renderer* renderer)
    : renderer(renderer) {
    
}

void SdlGuiRenderSystem::RenderTexture(SDL_Texture* texture, const SDL_Rect rect) const {
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}