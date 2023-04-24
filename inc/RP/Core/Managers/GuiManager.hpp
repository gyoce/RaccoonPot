#ifndef RP_GUI_MANAGER_HPP
#define RP_GUI_MANAGER_HPP

#include <memory>

#include <RP/Types.hpp>

namespace RP {

    class GuiManager {
    public:
        explicit GuiManager(int width, int height, IGuiRenderSystemPtr renderSystem);
        void RegisterEventManager(const EventManagerPtr& eventManager);
        void RegisterClickEvent(int event) const;
        void RegisterWindowResizeEvent(int event) const;
        template<class T, typename ...Args> std::shared_ptr<T> CreateWidget(Args&&... args);
        //template<class T, typename ...Args> std::shared_ptr<T> CreateWidget(const GuiWidgetPtr& parent, Args&&... args);
        void Render() const;

    private:
        static bool clickIsInsideButton(int x, int y, const GuiButtonPtr& button);
        void checkForClickOnWidgetButton(int x, int y) const;
        void windowResized(int width, int height) const;
         
        EventManagerPtr eventManager = nullptr;
        GuiPanelPtr mainPanel = nullptr;
        IGuiRenderSystemPtr renderSystem = nullptr;
    };

}

#include <RP/Core/Managers/GuiManager.inl>

#endif // RP_GUI_MANAGER_HPP