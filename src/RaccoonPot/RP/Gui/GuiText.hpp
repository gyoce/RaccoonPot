#ifndef GUI_TEXT_HPP
#define GUI_TEXT_HPP

#include <string>

#include "GuiWidget.hpp"

namespace RP {

    class GuiText : public GuiWidget {
    public:
        std::string Text;
    };

}

#endif // GUI_TEXT_HPP