#ifndef RP_GUI_WIDGET_HPP
#define RP_GUI_WIDGET_HPP

#include <vector>

#include <SDL2/SDL.h>
#include <RP/Types.hpp>
#include <RP/Math/Vector3Int.hpp>

namespace RP {

    class GuiWidget {
    public:
        virtual ~GuiWidget() = default;

        virtual void AddChild(const GuiWidgetPtr& widget);
        virtual void Draw(SDL_Renderer* renderer) = 0;
        virtual void SetPosition(int x, int y);

        int Width{}, Height{};
        Vector3Int Position{};
        Vector3Int LocalPosition{};
        std::vector<GuiWidgetPtr> Children{};
        GuiWidget* Parent = nullptr;
    };

}

#endif // RP_GUI_WIDGET_HPP