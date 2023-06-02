#ifndef RP_GUI_BUILDER_HPP
#define RP_GUI_BUILDER_HPP

#include <RP/Gui/GuiWidget.hpp>

namespace RP {

    template<class T> requires std::derived_from<T, GuiWidget>
    class GuiBuilder {
    public:
        GuiBuilder() {
            obj = new T();
        }

        T* operator->() {
            return obj;
        }

        T* Build() {
            return new T(*obj);
        }

    private:
        T* obj = nullptr;
    };

}

#endif // RP_GUI_BUILDER_HPP