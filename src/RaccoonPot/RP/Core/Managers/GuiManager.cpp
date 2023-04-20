#include "GuiManager.hpp"

#include "../../Gui/GuiButton.hpp"

using namespace RP;

void GuiManager::RegisterEventManager(const std::shared_ptr<EventManager>& eventManager) {
    this->eventManager = eventManager;
}

void GuiManager::RegisterClickEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int x, const int y) { checkForClickOnWidgetButton(x, y); });
}

void GuiManager::Render() const {
    for (const std::pair<const char*, std::shared_ptr<IWidgetFunction>> pair : mapWidgets) {
        pair.second->RenderWidgets();
    }
}

void GuiManager::checkForClickOnWidgetButton(const int x, const int y) const {
    for (const std::pair<const char*, std::shared_ptr<IWidgetFunction>> pair : mapWidgets) {
        for (const std::shared_ptr<GuiWidget>& widget : pair.second->Widgets) {
            std::shared_ptr<GuiButton> button = std::dynamic_pointer_cast<GuiButton>(widget);
            if (button == nullptr) {
                continue;
            }

            if (x >= button->x && x <= button->x + button->Width && y >= button->y && y <= button->y + button->Height) {
                button->Click();
            }
        }
    }
}