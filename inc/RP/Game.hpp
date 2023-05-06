#ifndef RP_GAME_HPP
#define RP_GAME_HPP

#include <SDL2/SDL.h>
#include <RP/Types.hpp>
#include <RP/GameOptions.hpp>
#include <RP/RPMacros.hpp>

namespace RP {

    class Game {
    public:
        explicit Game(GameOptions options = {});
        RP_DELETE_MISC_CONSTRUCTORS(Game)
        virtual ~Game();
        [[nodiscard]] int Run() const;

    protected:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SceneManagerPtr sceneManager = nullptr;
        ResourceManagerPtr resourceManager = nullptr;

    private:
        void init();
        static bool initSdl();
        static bool initTtf();
        static bool initSdlImage();
        bool initWindow();
        bool initRenderer();

        [[nodiscard]] int getRendererFlags() const;

        GameOptions options;
        bool isInitialized = false;
    };

}

#endif // RP_GAME_HPP