#ifndef RP_GUI_BUTTON_TEXTURE_HPP
#define RP_GUI_BUTTON_TEXTURE_HPP

#include <SDL2/SDL.h>
#include <RP/Gui/GuiButton.hpp>

namespace RP {

    class GuiButtonTexture: public GuiButton {
    public:
        explicit GuiButtonTexture(std::function<void()> callback, SDL_Texture* texture);
        void Draw(SDL_Renderer* renderer) override;

    protected:
        SDL_Texture* texture = nullptr;
    };
    using GuiButtonTexturePtr = std::shared_ptr<GuiButtonTexture>;

} // namespace RP

#endif // RP_GUI_BUTTON_TEXTURE_HPP