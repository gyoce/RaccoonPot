#include "RP/Core/Managers/ResourceManager.hpp"

#include <cassert>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "RP/Logs/Log.hpp"
#include "RP/Core/Resources/Font.hpp"
#include "RP/Core/Resources/SpriteSheet.hpp"

namespace RP
{

ResourceManager::ResourceManager(SDL_Renderer* renderer)
    : renderer(renderer) {  }

FontPtr ResourceManager::LoadFont(const std::string& path, const std::string& name, const int ptSize) {
    assert(!fonts.contains(name) && "Font name already exist in the ResourceManager.");

    TTF_Font* ttfFont = TTF_OpenFont(path.c_str(), ptSize);
    if (ttfFont == nullptr) {
        LogError("Error while opening font file: {}", SDL_GetError());
        return nullptr;
    }

    FontPtr font = std::make_shared<Font>(ttfFont);
    fonts.insert({ name, font });
    return font;
}

FontPtr ResourceManager::GetFontByName(const std::string& name) {
    assert(fonts.contains(name) && "Font not in resource manager.");
    return fonts[name];
}

SpriteSheetPtr ResourceManager::LoadSpriteSheet(const std::string& path, const std::string& name, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos) {
    assert(!spriteSheets.contains(name) && "SpriteSheet name already exist in the ResourceManager.");

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) {
        LogError("Error while loading image: {}", SDL_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr) {
        LogError("Error while creating texture from surface: {}", SDL_GetError());
        return nullptr;
    }

    SpriteSheetPtr spriteSheet = std::make_shared<SpriteSheet>(texture, renderer, spriteSheetInfos);
    spriteSheets.insert({ name, spriteSheet });
    return spriteSheet;
}

SpriteSheetPtr ResourceManager::GetSpriteSheetByName(const std::string& name) {
    assert(spriteSheets.contains(name) && "SpriteSheet not in resource manager.");
    return spriteSheets[name];
}

} // namespace RP