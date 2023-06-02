#include "RP/Core/Managers/GuiManager.hpp"

#include <stack>
#include <cassert>

#include "RP/Core/Managers/EventManager.hpp"
#include "RP/Gui/GuiButton.hpp"
#include "RP/Gui/GuiPanel.hpp"

namespace RP
{
    
GuiManager::GuiManager() {
    mainPanel = new GuiPanel();
}

GuiManager::~GuiManager() {
    delete mainPanel;
}

void GuiManager::RegisterEventManager(const EventManagerPtr& eventManager) {
    this->eventManager = eventManager;
}

void GuiManager::RegisterClickEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int x, const int y) { mouseClick(x, y); });
}

void GuiManager::RegisterWindowResizeEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int width, const int height) { windowResized(width, height); });
}

void GuiManager::RegisterMouseMoveEvent(const int event) const {
    assert(eventManager != nullptr && "Event Manager not registered.");
    eventManager->Bind<void(int, int)>(event, [this](const int x, const int y) { mouseMove(x, y); });
}

void GuiManager::AddToMainPanel(GuiWidget* widget) const {
    mainPanel->AddChild(widget);
}

void GuiManager::Render(SDL_Renderer* renderer) const {
    std::stack<GuiWidget*> stackOfWidgets{};
    stackOfWidgets.push(mainPanel);
    while (!stackOfWidgets.empty()) {
        GuiWidget* widget = stackOfWidgets.top();
        stackOfWidgets.pop();
        widget->Draw(renderer);
        for (GuiWidget* subWidget : widget->Children) {
            stackOfWidgets.push(subWidget);
        }
    }
}

void GuiManager::mouseClick(const int x, const int y) const {
    std::stack<GuiWidget*> stackOfWidgets{};
    stackOfWidgets.push(mainPanel);
    while (!stackOfWidgets.empty()) {
        GuiWidget* widget = stackOfWidgets.top();
        stackOfWidgets.pop();

        if (auto* button = dynamic_cast<GuiButton*>(widget); button != nullptr && positionIsInsideWidget(x, y, button)) {
            button->Click();
        }

        for (GuiWidget* subWidget : widget->Children) {
            stackOfWidgets.push(subWidget);
        }
    }
}

void GuiManager::mouseMove(const int x, const int y) const {
    std::stack<GuiWidget*> stackOfWidgets{};
    stackOfWidgets.push(mainPanel);
    while (!stackOfWidgets.empty()) {
        GuiWidget* widget = stackOfWidgets.top();
        stackOfWidgets.pop();

        if (widget->IsHoverable()) {
            widget->SetHover(positionIsInsideWidget(x, y, widget));
        }

        for (GuiWidget* subWidget : widget->Children) {
            stackOfWidgets.push(subWidget);
        }
    }
}

bool GuiManager::positionIsInsideWidget(const int x, const int y, GuiWidget* widget) {
    const Vector3Int& position = widget->GetPosition();
    return x >= position.x && x <= position.x + widget->GetWidth() && y >= position.y && y <= position.y + widget->GetHeight();
}

void GuiManager::windowResized(const int width, const int height) const {
    mainPanel->SetSize(width, height);
}

} // namespace RP