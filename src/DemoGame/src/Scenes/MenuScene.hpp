#ifndef MENU_SCENE_HPP
#define MENU_SCENE_HPP

#include <RP/RP.hpp>

class MenuScene final : public RP::Scene {
public:
    void Init();

private:
    void initGui();
};

#endif // MENU_SCENE_HPP