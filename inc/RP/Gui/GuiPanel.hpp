#ifndef RP_GUI_PANEL_HPP
#define RP_GUI_PANEL_HPP

#include <RP/Gui/GuiWidget.hpp>

namespace RP {

    class GuiPanel: public GuiWidget {
    public:
        void Draw(const IGuiRenderSystemPtr& renderSystem) override;
    };

}

#endif // RP_GUI_PANEL_HPP