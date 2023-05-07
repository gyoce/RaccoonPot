#include "RP/Core/Managers/GuiManager.hpp"

#include <stack>
#include <cassert>

#include "RP/Core/Managers/EventManager.hpp"
#include "RP/Gui/GuiButton.hpp"

namespace RP
{
    
GuiManager::GuiManager() {
    mainPanel = std::make_shared<GuiWidget>();
}

void GuiManager::RegisterEventManager(const EventManagerPtr& eventManager) {
    this->eventManager = eventManager;
}

void GuiManager::RegisterClickEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int x, const int y) { checkForClickOnWidgetButton(x, y); });
}

void GuiManager::RegisterWindowResizeEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int width, const int height) { windowResized(width, height); });
}

void GuiManager::AddToMainPanel(const GuiWidgetPtr& widget) const {
    mainPanel->AddChild(widget);
}

void GuiManager::Render(SDL_Renderer* renderer) const {
    std::stack<GuiWidgetPtr> stackOfWidgets{};
    stackOfWidgets.push(mainPanel);
    while (!stackOfWidgets.empty()) {
        const GuiWidgetPtr widget = stackOfWidgets.top();
        stackOfWidgets.pop();
        widget->Draw(renderer);
        for (const GuiWidgetPtr& subWidget : widget->Children) {
            stackOfWidgets.push(subWidget);
        }
    }
}

void GuiManager::checkForClickOnWidgetButton(const int x, const int y) const {
    std::stack<GuiWidgetPtr> stackOfWidgets{};
    stackOfWidgets.push(mainPanel);
    while (!stackOfWidgets.empty()) {
        const GuiWidgetPtr widget = stackOfWidgets.top();
        stackOfWidgets.pop();

        if (GuiButtonPtr button = std::dynamic_pointer_cast<GuiButton>(widget); button != nullptr && clickIsInsideButton(x, y, button)) {
            button->Click();
        }

        for (const GuiWidgetPtr& subWidget : widget->Children) {
            stackOfWidgets.push(subWidget);
        }
    }
}

bool GuiManager::clickIsInsideButton(const int x, const int y, const GuiButtonPtr& button) {
    return x >= button->Position.x && x <= button->Position.x + button->Width && y >= button->Position.y && y <= button->Position.y + button->Height;
}

void GuiManager::windowResized(const int width, const int height) const {
    mainPanel->SetSize(width, height);
}

} // namespace RP