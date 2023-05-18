#ifndef RP_GUI_BUTTON_HPP
#define RP_GUI_BUTTON_HPP

#include <functional>

#include <RP/Gui/GuiWidget.hpp>

namespace RP {

    class GuiButton: public GuiWidget {
    public:
        explicit GuiButton(std::function<void()> callback);

        virtual void Click();
        void Draw(SDL_Renderer* renderer) override;
        virtual void SetBackgroundColor(SDL_Color color);

    protected:
        std::function<void()> callback;
        SDL_Color backgroundColor{};
    };
    using GuiButtonPtr = std::shared_ptr<GuiButton>;

} // namespace RP

#endif // RP_GUI_BUTTON_HPP