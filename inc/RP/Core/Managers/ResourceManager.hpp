#ifndef RP_RESOURCE_MANAGER_HPP
#define RP_RESOURCE_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include <SDL2/SDL.h>
#include <RP/Types.hpp>

namespace RP {

    class ResourceManager {
    public:
        explicit ResourceManager(SDL_Renderer* renderer);

        FontPtr LoadFont(const std::string& path, const std::string& name, int ptSize);
        SpriteSheetPtr LoadSpriteSheet(const std::string& path, const std::string& name, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos);

    private:
        SDL_Renderer* renderer = nullptr;
        std::unordered_map<std::string, SpriteSheetPtr> spriteSheets{};
        std::unordered_map<std::string, FontPtr> fonts{};
    };

}

#endif // RP_RESOURCE_MANAGER_HPP