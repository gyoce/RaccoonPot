#ifndef GUI_TEXT_HPP
#define GUI_TEXT_HPP

#include <string>
#include <SDL2/SDL.h>
#include <RP/Gui/GuiWidget.hpp>
#include <RP/Types.hpp>

namespace RP {

    class GuiText: public GuiWidget {
    public:
        explicit GuiText(std::string text, const FontPtr& font);

        void Draw(SDL_Renderer* renderer) override;

    protected:
        SDL_Texture* textTexture = nullptr;
        std::string text;
    };

} // namespace RP

#endif // GUI_TEXT_HPP