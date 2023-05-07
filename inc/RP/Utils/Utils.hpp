#ifndef RP_UTILS_HPP
#define RP_UTILS_HPP

#include <SDL2/SDL.h>

namespace RP::Utils {

    SDL_Texture* ExtractTextureFromSource(const SDL_Rect& rect, SDL_Renderer* renderer, SDL_Texture* source);

} // namespace RP::Utils

#endif // RP_UTILS_HPP