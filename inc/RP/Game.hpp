#ifndef RP_GAME_HPP
#define RP_GAME_HPP

#include <SDL2/SDL.h>
#include <RP/Types.hpp>

namespace RP {

    class Game {
    public:
        Game();
        virtual ~Game();
        int Run() const;

    protected:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SceneManagerPtr sceneManager = nullptr;

    private:
        void init();
        static bool initSdl();
        bool initWindow();
        bool initRenderer();

        bool isInitialized = false;
    };

}

#endif // RP_GAME_HPP