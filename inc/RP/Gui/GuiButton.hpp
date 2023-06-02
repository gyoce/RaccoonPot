#ifndef RP_GUI_BUTTON_HPP
#define RP_GUI_BUTTON_HPP

#include <functional>

#include <RP/Gui/GuiWidget.hpp>

namespace RP {

    class GuiButton: public GuiWidget {
    public:
        GuiButton() = default;
        GuiButton(const GuiButton& guiButton);

        virtual void SetBackgroundColor(SDL_Color color);
        virtual void SetCallback(std::function<void()> callback);

        virtual void Click();
        void Draw(SDL_Renderer* renderer) override;

    protected:
        std::function<void()> callback = nullptr;
        SDL_Color backgroundColor{};
    };

} // namespace RP

#endif // RP_GUI_BUTTON_HPP