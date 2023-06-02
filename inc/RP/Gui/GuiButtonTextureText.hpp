#ifndef RP_GUI_BUTTON_TEXTURE_TEXT_HPP
#define RP_GUI_BUTTON_TEXTURE_TEXT_HPP

#include <RP/Gui/GuiButtonTexture.hpp>
#include <RP/Gui/GuiText.hpp>

namespace RP {

    class GuiButtonTextureText: public GuiButtonTexture {
    public:
        GuiButtonTextureText() = default;
        
        void SetSize(int width, int height) override;
        virtual void SetText(const std::string& text, const FontPtr& font);

    protected:
        GuiText* guiText = nullptr;
    };

} // namespace RP

#endif // RP_GUI_BUTTON_TEXTURE_TEXT_HPP