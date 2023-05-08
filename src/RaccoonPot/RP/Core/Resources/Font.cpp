#include "RP/Core/Resources/Font.hpp"

#include "RP/Logs/Log.hpp"

namespace RP
{

Font::Font(TTF_Font* font, SDL_Renderer* renderer)
    : font(font), renderer(renderer) {  }

Font::~Font() {
    TTF_CloseFont(font);
}

// TODO: Color
SDL_Texture* Font::GetTextTextureForText(const std::string& text) const {
    constexpr SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr) {
        Log("Error while creating text: {}", SDL_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        Log("Error while creating texture from surface: {}", SDL_GetError());
        return nullptr;
    }
    return texture;
}

} // namespace RP