#include "RP/Core/Resources/Font.hpp"

namespace RP
{

Font::Font(TTF_Font* font)
    : font(font) {  }

Font::~Font() {
    TTF_CloseFont(font);
}

}