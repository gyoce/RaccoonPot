#include "Utils.hpp"

#include <RP/RP.hpp>

SDL_Texture* Utils::ExtractTextureFromSource(const SDL_Rect& rect, SDL_Renderer* renderer, SDL_Texture* source) {
    SDL_Texture* result = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
    if (result == nullptr) {
        RP::LogError("Error while extracting texture from source : %s ", SDL_GetError());
        return nullptr;
    }
    SDL_SetRenderTarget(renderer, result);
    SDL_RenderCopy(renderer, source, &rect, nullptr);
    SDL_SetRenderTarget(renderer, nullptr);
    return result;
}