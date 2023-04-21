#ifndef RP_GUI_WIDGET_HPP
#define RP_GUI_WIDGET_HPP

namespace RP {

    class GuiWidget {
    public:
        virtual ~GuiWidget() = default;
        int x, y, Width, Height;
    };

}

#endif // RP_GUI_WIDGET_HPP