#ifndef GUI_BUTTON_TEXT_HPP
#define GUI_BUTTON_TEXT_HPP

#include <memory>

#include "GuiButton.hpp"
#include "GuiText.hpp"

namespace RP {

    class GuiButtonText : public GuiButton {
    public:
        std::unique_ptr<GuiText> GuiText = nullptr;
    };

}

#endif // GUI_BUTTON_TEXT_HPP