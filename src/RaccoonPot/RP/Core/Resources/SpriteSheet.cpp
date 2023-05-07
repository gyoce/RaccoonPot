#include "RP/Core/Resources/SpriteSheet.hpp"

#include <cassert>

#include "RP/Utils/Utils.hpp"

namespace RP
{

SpriteSheet::SpriteSheet(SDL_Texture* texture, SDL_Renderer* renderer, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos)
    : mainTexture(texture) {
    initTextures(renderer, spriteSheetInfos);
}

SpriteSheet::~SpriteSheet() {
    SDL_DestroyTexture(mainTexture);
    for (const auto& [first, second] : textures) {
        SDL_DestroyTexture(second);
    }
}

SDL_Texture* SpriteSheet::GetTextureByName(const std::string& name) {
    assert(textures.contains(name) && "Name not in sprite sheet.");
    return textures[name];
}

void SpriteSheet::initTextures(SDL_Renderer* renderer, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos) {
    for(const auto& [first, second] : spriteSheetInfos) {
        assert(!textures.contains(first) && "Name for sprite texture already used.");
        SDL_Texture* texture = Utils::ExtractTextureFromSource(second, renderer, mainTexture);
        textures.insert({ first, texture });
    }
}

}