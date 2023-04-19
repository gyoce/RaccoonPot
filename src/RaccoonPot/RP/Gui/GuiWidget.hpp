#ifndef GUI_WIDGET_HPP
#define GUI_WIDGET_HPP

namespace RP {

    class GuiWidget {
    public:
        virtual ~GuiWidget() = default;
        int x, y, Width, Height;
    };

}

#endif // GUI_WIDGET_HPP