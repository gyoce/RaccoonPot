#ifndef RP_GUI_PANEL_HPP
#define RP_GUI_PANEL_HPP

#include <RP/Gui/GuiWidget.hpp>

namespace RP {

    class GuiPanel: public GuiWidget {
    public:
        GuiPanel() = default;
        GuiPanel(const GuiPanel& guiPanel);
        void Draw(SDL_Renderer* renderer) override;
        virtual void SetBackgroundColor(SDL_Color color);

    protected:
        SDL_Color backgroundColor{};
    };

} // namespace RP

#endif // RP_GUI_PANEL_HPP