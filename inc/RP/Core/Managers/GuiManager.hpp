#ifndef RP_GUI_MANAGER_HPP
#define RP_GUI_MANAGER_HPP

#include <memory>

#include <SDL2/SDL.h>
#include <RP/Gui/GuiPanel.hpp>
#include <RP/Gui/GuiButton.hpp>
#include <RP/Core/Managers/EventManager.hpp>

namespace RP {

    class GuiManager {
    public:
        GuiManager();
        ~GuiManager();
        void RegisterEventManager(const EventManagerPtr& eventManager);
        void RegisterClickEvent(int event) const;
        void RegisterWindowResizeEvent(int event) const;
        void RegisterMouseMoveEvent(int event) const;
        void AddToMainPanel(GuiWidget* widget) const;
        void Render(SDL_Renderer* renderer) const;

    private:
        static bool positionIsInsideWidget(int x, int y, GuiWidget* widget);
        void mouseClick(int x, int y) const;
        void mouseMove(int x, int y) const;
        void windowResized(int width, int height) const;
         
        GuiPanel* mainPanel = nullptr;
        EventManagerPtr eventManager = nullptr;
    };
    using GuiManagerPtr = std::shared_ptr<GuiManager>;

} // namespace RP

#endif // RP_GUI_MANAGER_HPP