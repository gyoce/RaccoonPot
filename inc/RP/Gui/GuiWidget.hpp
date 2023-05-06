#ifndef RP_GUI_WIDGET_HPP
#define RP_GUI_WIDGET_HPP

#include <vector>

#include <SDL2/SDL.h>
#include <RP/Types.hpp>
#include <RP/Math/Vector3Int.hpp>
#include <RP/Gui/Anchors.hpp>

namespace RP {

    class GuiWidget {
    public:
        virtual ~GuiWidget() = default;

        virtual void AddChild(const GuiWidgetPtr& widget);
        virtual void Draw(SDL_Renderer* renderer);
        virtual void SetPosition(int x, int y);
        virtual void SetSize(int width, int height);
        virtual void SetAnchor(HorizontalAnchor horizontalAnchor, VerticalAnchor verticalAnchor);

        int Width{}, Height{};
        Vector3Int Position{};
        Vector3Int LocalPosition{};
        std::vector<GuiWidgetPtr> Children{};
        GuiWidget* Parent = nullptr;

    protected:
        void UpdateChildrenPositions() const;

        HorizontalAnchor horizontalAnchor = HorizontalAnchor::None;
        VerticalAnchor verticalAnchor = VerticalAnchor::None;

    private:
        [[nodiscard]] int getCorrectiveHeight(int indexOfChild) const;
    };

}

#endif // RP_GUI_WIDGET_HPP