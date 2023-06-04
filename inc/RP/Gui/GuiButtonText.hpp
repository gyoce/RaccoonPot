#ifndef RP_GUI_BUTTON_TEXT_HPP
#define RP_GUI_BUTTON_TEXT_HPP

#include <RP/Gui/GuiButton.hpp>
#include <RP/Gui/GuiText.hpp>

namespace RP {

    class GuiButtonText: public GuiButton {
    public:
        GuiButtonText() = default;
        GuiButtonText(const GuiButtonText& guiButtonText);

        void SetPosition(int x, int y) override;
        virtual void SetPadding(int padding);
        virtual void SetText(const std::string& text, const FontPtr& font);

        [[nodiscard]] GuiText* GetGuiText() const;

    protected:
        GuiText* guiText = nullptr;
        int paddingWithText{};
    };

} // namespace RP

#endif // RP_GUI_BUTTON_TEXT_HPP