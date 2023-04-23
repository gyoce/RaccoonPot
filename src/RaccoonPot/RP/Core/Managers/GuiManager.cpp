#include "RP/Core/Managers/GuiManager.hpp"

#include "RP/Gui/GuiButton.hpp"

using namespace RP;

void GuiManager::RegisterEventManager(const EventManagerPtr& eventManager) {
    this->eventManager = eventManager;
}

void GuiManager::RegisterClickEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int x, const int y) { checkForClickOnWidgetButton(x, y); });
}

void GuiManager::Render() const {
    for (const std::pair<const char*, IWidgetFunctionPtr> pair : mapWidgets) {
        pair.second->RenderWidgets();
    }
}

void GuiManager::checkForClickOnWidgetButton(const int x, const int y) const {
    for (const std::pair<const char*, IWidgetFunctionPtr> pair : mapWidgets) {
        for (const GuiWidgetPtr& widget : pair.second->Widgets) {
            GuiButtonPtr button = std::dynamic_pointer_cast<GuiButton>(widget);
            if (button == nullptr) {
                continue;
            }

            if (x >= button->x && x <= button->x + button->Width && y >= button->y && y <= button->y + button->Height) {
                button->Click();
            }
        }
    }
}