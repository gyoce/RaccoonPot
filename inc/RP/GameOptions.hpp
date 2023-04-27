#ifndef RP_GAME_OPTIONS_HPP
#define RP_GAME_OPTIONS_HPP

#include <string>

namespace RP {

    struct GameOptions {
        bool VSync = false;
        int Width = 1280;
        int Height = 720;
        std::string Title = "GameTitle";
    };

}

#endif // RP_GAME_OPTIONS_HPP