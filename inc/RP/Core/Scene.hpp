#ifndef RP_SCENE_HPP
#define RP_SCENE_HPP

#include <SDL2/SDL.h>
#include <RP/Types.hpp>

namespace RP {

    class Scene {
    public:
        explicit Scene(SDL_Renderer* renderer);
        virtual ~Scene() = default;
        virtual int Loop();

    protected:
        virtual void Event();
        virtual void Update(double dt);
        virtual void Draw();

        bool run = false;
        int action{};
        SDL_Renderer* renderer = nullptr;
        EventManagerPtr eventManager = nullptr;
        GuiManagerPtr guiManager = nullptr;
    };

} // namespace RP

#endif // RP_SCENE_HPP