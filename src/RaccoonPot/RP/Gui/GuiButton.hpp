#ifndef GUI_CLICKABLE_HPP
#define GUI_CLICKABLE_HPP

#include "GuiWidget.hpp"

namespace RP {

    class GuiButton: public GuiWidget {
    public:
        virtual void Click() = 0;
    };

}

#endif // GUI_CLICKABLE_HPP