#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <SDL2/SDL.h>

struct Renderable {
    SDL_Texture* texture = nullptr;
};

#endif // RENDERABLE_HPP