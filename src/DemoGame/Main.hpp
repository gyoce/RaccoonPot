#ifndef GAME_MAIN_HPP
#define GAME_MAIN_HPP

#include <RP/RP.hpp>

const std::vector<std::pair<std::string, SDL_Rect>> SpriteSheetInfos{
    { "ButtonSort", { 0, 0, 192, 64 }},
    { "ButtonGame", { 0, 64, 192, 64 }}
};

const RP::GameOptions Options{
    .VSync = true,
    .Width = 1920,
    .Height = 1080,
    .Title = "DemoGame",
};

enum SceneAction {
    SaQuit,
    SaMenu,
    SaGame
};

#endif // GAME_MAIN_HPP