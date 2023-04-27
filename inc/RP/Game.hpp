#ifndef RP_GAME_HPP
#define RP_GAME_HPP

#include <SDL2/SDL.h>
#include <RP/Types.hpp>
#include <RP/GameOptions.hpp>

namespace RP {

    class Game {
    public:
        explicit Game(GameOptions options = {});
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

        int getFlagsForRenderer() const;

        GameOptions options;
        bool isInitialized = false;
    };

}

#endif // RP_GAME_HPP