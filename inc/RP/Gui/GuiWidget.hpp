#ifndef RP_GUI_WIDGET_HPP
#define RP_GUI_WIDGET_HPP

#include <vector>

#include <SDL2/SDL.h>
#include <RP/RPMacros.hpp>
#include <RP/Types.hpp>
#include <RP/Gui/Anchors.hpp>
#include <RP/Gui/AlignItems.hpp>
#include <RP/Math/Vector3Int.hpp>

namespace RP {

    class GuiWidget {
    public:
        explicit GuiWidget() = default;
        virtual ~GuiWidget() = default;
        RP_DELETE_MISC_CONSTRUCTORS(GuiWidget)

        virtual void SetPosition(int x, int y);
        virtual void SetSize(int width, int height);
        virtual void SetAnchor(HorizontalAnchor horizontalAnchor, VerticalAnchor verticalAnchor);
        virtual void SetHorizontalAnchor(HorizontalAnchor anchor);
        virtual void SetVerticalAnchor(VerticalAnchor anchor);
        virtual void SetAlignItems(AlignItems alignItems);
        virtual void SetPaddingBetweenChildren(int padding);
        virtual Vector3Int& GetPosition();
        virtual int GetWidth();
        virtual int GetHeight();
        virtual void AddChild(const GuiWidgetPtr& widget);
        virtual void Draw(SDL_Renderer* renderer) = 0;

        std::vector<GuiWidgetPtr> Children{};
        GuiWidget* Parent = nullptr;

    protected:
        void UpdateChildrenPosition() const;
        void UpdateChildrenSize(float widthFactor, float heightFactor) const;
        void CallUpdatePositionForChildren() const;

        HorizontalAnchor horizontalAnchor = HorizontalAnchor::None;
        VerticalAnchor verticalAnchor = VerticalAnchor::None;
        AlignItems alignItems = AlignItems::Column;
        int width{}, height{};
        Vector3Int position{};
        int paddingBetweenChildren{};

    private:
        [[nodiscard]] int getCorrectiveHeight(int indexOfChild) const;
        [[nodiscard]] int getCorrectiveWidth(int indexOfChild) const;
    };

} // namespace RP

#endif // RP_GUI_WIDGET_HPP