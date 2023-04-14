#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <Core/Scene.hpp>

class MenuScene : public ECSGameEngine::Scene {
public:
    SCENE_CONSTRUCTOR(MenuScene)
    int Loop() override;
};

#endif // MENU_SCENE_HPP