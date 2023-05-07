#ifndef RP_SPRITE_SHEET_HPP
#define RP_SPRITE_SHEET_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include <SDL2/SDL.h>
#include <RP/RPMacros.hpp>

namespace RP {

    class SpriteSheet {
    public:
        explicit SpriteSheet(SDL_Texture* texture, SDL_Renderer* renderer, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos);
        ~SpriteSheet();
        RP_DELETE_MISC_CONSTRUCTORS(SpriteSheet)

        SDL_Texture* GetTextureByName(const std::string& name);

    private:
        void initTextures(SDL_Renderer* renderer, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos);

        std::unordered_map<std::string, SDL_Texture*> textures{};
        SDL_Texture* mainTexture = nullptr;
    };

}

#endif // RP_SPRITE_SHEET_HPP