#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>

namespace Utils {

    SDL_Texture* ExtractTextureFromSource(const SDL_Rect& rect, SDL_Renderer* renderer, SDL_Texture* source);

}

#endif // UTILS_HPP