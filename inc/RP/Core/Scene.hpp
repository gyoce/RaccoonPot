#ifndef RP_SCENE_HPP
#define RP_SCENE_HPP

#include <SDL2/SDL.h>
#include <RP/Types.hpp>

namespace RP {

    class Scene {
    public:
        Scene();
        virtual ~Scene() = default;
        virtual int Loop();
        void SetRenderer(SDL_Renderer* renderer);

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

}

#endif // RP_SCENE_HPP