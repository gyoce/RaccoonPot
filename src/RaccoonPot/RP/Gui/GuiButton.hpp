#ifndef RP_GUI_BUTTON_HPP
#define RP_GUI_BUTTON_HPP

#include "GuiWidget.hpp"

namespace RP {

    class GuiButton: public GuiWidget {
    public:
        virtual void Click() = 0;
    };

}

#endif // RP_GUI_BUTTON_HPP