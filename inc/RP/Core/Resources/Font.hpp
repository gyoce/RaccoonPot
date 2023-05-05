#ifndef RP_FONT_HPP
#define RP_FONT_HPP

#include <SDL2/SDL_ttf.h>
#include <RP/RPMacros.hpp>

namespace RP {

    class Font {
    public:
        explicit Font(TTF_Font* font);
        ~Font();
        RP_DELETE_MISC_CONSTRUCTORS(Font)

    private:
        TTF_Font* font;
    };

}

#endif // RP_FONT_HPP