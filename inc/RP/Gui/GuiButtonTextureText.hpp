#ifndef RP_GUI_BUTTON_TEXTURE_TEXT_HPP
#define RP_GUI_BUTTON_TEXTURE_TEXT_HPP

#include <RP/Gui/GuiButtonTexture.hpp>

namespace RP {

    class GuiButtonTextureText: public GuiButtonTexture {
    public:
        explicit GuiButtonTextureText(const std::function<void()>& callback, SDL_Texture* texture, const std::string& text, const FontPtr& font);
        
        void SetSize(int width, int height) override;

    protected:
        GuiTextPtr guiText = nullptr;
    };

} // namespace RP

#endif // RP_GUI_BUTTON_TEXTURE_TEXT_HPP