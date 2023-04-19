#include "GuiManager.hpp"

using namespace RP;

void GuiManager::RegisterEventManager(const std::shared_ptr<EventManager>& eventManager) {
    this->eventManager = eventManager;
}


void GuiManager::Render() const {
    for (const std::pair<const char*, std::shared_ptr<IWidgetFunction>> pair : mapWidgets) {
        pair.second->RenderWidgets();
    }
}
