#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <RP/RP.hpp>

class GameScene final : public RP::Scene {
public:
    void Init();

private:
    void initGui();
};

#endif // GAME_SCENE_HPP