#ifndef SDL_GUI_RENDER_SYSTEM_HPP
#define SDL_GUI_RENDER_SYSTEM_HPP

#include <SDL2/SDL.h>
#include <RP/RP.hpp>

class SdlGuiRenderSystem final : public RP::IGuiRenderSystem {
public:
    explicit SdlGuiRenderSystem(SDL_Renderer* renderer);
    void RenderTexture(SDL_Texture* texture, SDL_Rect rect) const;

private:
    SDL_Renderer* renderer = nullptr;
};

#endif // SDL_GUI_RENDER_SYSTEM_HPP