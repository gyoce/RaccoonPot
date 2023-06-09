#ifndef RP_FONT_HPP
#define RP_FONT_HPP

#include <memory>
#include <string>

#include <SDL2/SDL_ttf.h>
#include <RP/RPMacros.hpp>

namespace RP {

    class Font {
    public:
        Font(TTF_Font* font, SDL_Renderer* renderer);
        ~Font();
        RP_DELETE_MISC_CONSTRUCTORS(Font)

        [[nodiscard]] SDL_Texture* GetTextTextureForText(const std::string& text) const;

    private:
        TTF_Font* font = nullptr;
        SDL_Renderer* renderer = nullptr;
    };
    using FontPtr = std::shared_ptr<Font>;

} // namespace RP

#endif // RP_FONT_HPP