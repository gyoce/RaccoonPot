#ifndef GUI_BUTTON_TEXTURE_HPP
#define GUI_BUTTON_TEXTURE_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

class GuiButtonTexture : public RP::GuiButton {
public:
    ~GuiButtonTexture() override;
    void Click() override;

    SDL_Texture* Texture = nullptr;
};

#endif // GUI_BUTTON_TEXTURE_HPP