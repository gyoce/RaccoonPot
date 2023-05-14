#ifndef RP_GUI_MANAGER_HPP
#define RP_GUI_MANAGER_HPP

#include <memory>

#include <SDL2/SDL.h>
#include <RP/Types.hpp>

namespace RP {

    class GuiManager {
    public:
        GuiManager();
        void RegisterEventManager(const EventManagerPtr& eventManager);
        void RegisterClickEvent(int event) const;
        void RegisterWindowResizeEvent(int event) const;
        template<class T, typename ...Args> std::shared_ptr<T> CreateWidget(Args&&... args);
        void AddToMainPanel(const GuiWidgetPtr& widget) const;
        void Render(SDL_Renderer* renderer) const;

    private:
        static bool clickIsInsideButton(int x, int y, const GuiButtonPtr& button);
        void checkForClickOnWidgetButton(int x, int y) const;
        void windowResized(int width, int height) const;
         
        GuiPanelPtr mainPanel = nullptr;
        EventManagerPtr eventManager = nullptr;
    };

} // namespace RP

#include <RP/Core/Managers/GuiManager.inl>

#endif // RP_GUI_MANAGER_HPP