#include "RP/Utils/Utils.hpp"

#include "RP/Logs/Log.hpp"

namespace RP::Utils
{

SDL_Texture* ExtractTextureFromSource(const SDL_Rect& rect, SDL_Renderer* renderer, SDL_Texture* source) {
    SDL_Texture* result = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
    if (result == nullptr) {
        LogError("Error while extracting texture from source: {} ", SDL_GetError());
        return nullptr;
    }
    SDL_SetTextureBlendMode(result, SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, result);
    SDL_RenderCopy(renderer, source, &rect, nullptr);
    SDL_SetRenderTarget(renderer, nullptr);
    return result;
}

} // namespace RP::Utils