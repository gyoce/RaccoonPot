#ifndef GUI_BUTTON_TEXTURE_HPP
#define GUI_BUTTON_TEXTURE_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

class GuiButtonTexture : public RP::GuiButton {
public:
    explicit GuiButtonTexture(std::function<void()> callback);
    ~GuiButtonTexture() override;
    void Click() override;

    SDL_Texture* Texture = nullptr;

private:
    std::function<void()> callback;
};

#endif // GUI_BUTTON_TEXTURE_HPP