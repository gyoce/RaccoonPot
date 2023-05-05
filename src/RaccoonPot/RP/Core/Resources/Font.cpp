#include "RP/Core/Resources/Font.hpp"

namespace RP
{

Font::Font(TTF_Font* font)
    : font(font) {  }

Font::~Font() {
    if (font != nullptr) { TTF_CloseFont(font); }
}

}