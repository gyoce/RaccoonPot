#ifndef RP_SPRITE_SHEET_HPP
#define RP_SPRITE_SHEET_HPP

#include <SDL2/SDL.h>
#include <RP/RPMacros.hpp>

namespace RP {

    class SpriteSheet {
    public:
        explicit SpriteSheet(SDL_Texture* texture);
        ~SpriteSheet();
        RP_DELETE_MISC_CONSTRUCTORS(SpriteSheet)

    private:
        SDL_Texture* texture = nullptr;
    };

}

#endif // RP_SPRITE_SHEET_HPP