#ifndef RP_GUI_PANEL_HPP
#define RP_GUI_PANEL_HPP

#include <RP/Gui/GuiWidget.hpp>

namespace RP {

    class GuiPanel: public GuiWidget {
    public:
        explicit GuiPanel() = default;
        void Draw(SDL_Renderer* renderer) override;
        virtual void SetBackgroundColor(SDL_Color color);

    protected:
        SDL_Color backgroundColor{};
    };
    using GuiPanelPtr = std::shared_ptr<GuiPanel>;

} // namespace RP

#endif // RP_GUI_PANEL_HPP