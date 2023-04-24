#ifndef RP_GUI_WIDGET_HPP
#define RP_GUI_WIDGET_HPP

#include <vector>

#include <RP/Types.hpp>
#include <RP/Math/Vector3Int.hpp>

namespace RP {

    class GuiWidget {
    public:
        virtual ~GuiWidget() = default;

        virtual void AddChild(const GuiWidgetPtr& widget);
        virtual void Draw(const IGuiRenderSystemPtr& renderSystem) = 0;

        int Width, Height;
        Vector3Int Position{};
        Vector3Int LocalPosition{};
        std::vector<GuiWidgetPtr> Children{};
        GuiWidget* Parent = nullptr;
    };

}

#endif // RP_GUI_WIDGET_HPP