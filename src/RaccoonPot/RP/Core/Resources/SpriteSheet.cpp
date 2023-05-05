#include "RP/Core/Resources/SpriteSheet.hpp"

namespace RP
{

SpriteSheet::SpriteSheet(SDL_Texture* texture)
    : texture(texture) {  }

SpriteSheet::~SpriteSheet() {
    if (texture != nullptr) { SDL_DestroyTexture(texture); }
}

}