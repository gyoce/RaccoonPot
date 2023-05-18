#ifndef RP_GUI_BUTTON_TEXT_HPP
#define RP_GUI_BUTTON_TEXT_HPP

#include <RP/Gui/GuiButton.hpp>
#include <RP/Gui/GuiText.hpp>

namespace RP {

    class GuiButtonText: public GuiButton {
    public:
        explicit GuiButtonText(std::function<void()> callback, const std::string& text, const FontPtr& font);
        void SetSize(int width, int height) override;
        void SetPosition(int x, int y) override;
        void SetPadding(int padding);
        GuiTextPtr& GetGuiText();

    protected:
        GuiTextPtr guiText = nullptr;
        int paddingWithText{};
    };
    using GuiButtonTextPtr = std::shared_ptr<GuiButtonText>;

} // namespace RP

#endif // RP_GUI_BUTTON_TEXT_HPP