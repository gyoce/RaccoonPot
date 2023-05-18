#ifndef RP_RESOURCE_MANAGER_HPP
#define RP_RESOURCE_MANAGER_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <SDL2/SDL.h>
#include <RP/Core/Resources/Font.hpp>
#include <RP/Core/Resources/SpriteSheet.hpp>

namespace RP {

    class ResourceManager {
    public:
        explicit ResourceManager(SDL_Renderer* renderer);

        FontPtr LoadFont(const std::string& path, const std::string& name, int ptSize);
        FontPtr GetFontByName(const std::string& name);
        SpriteSheetPtr LoadSpriteSheet(const std::string& path, const std::string& name, const std::vector<std::pair<std::string, SDL_Rect>>& spriteSheetInfos);
        SpriteSheetPtr GetSpriteSheetByName(const std::string& name);

    private:
        SDL_Renderer* renderer = nullptr;
        std::unordered_map<std::string, SpriteSheetPtr> spriteSheets{};
        std::unordered_map<std::string, FontPtr> fonts{};
    };
    using ResourceManagerPtr = std::shared_ptr<ResourceManager>;

} // namespace RP

#endif // RP_RESOURCE_MANAGER_HPP