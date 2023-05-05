#ifndef RP_RESOURCE_MANAGER_HPP
#define RP_RESOURCE_MANAGER_HPP

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <RP/Types.hpp>

namespace RP {

    class ResourceManager {
    public:
        FontPtr LoadFont(const std::string& path, const std::string& name, int ptSize);
        SpriteSheetPtr LoadSpriteSheet(const std::string& path, const std::string& name, SDL_Renderer* renderer);

    private:
        std::unordered_map<std::string, SpriteSheetPtr> spriteSheets{};
        std::unordered_map<std::string, FontPtr> fonts{};
    };

}

#endif // RP_RESOURCE_MANAGER_HPP