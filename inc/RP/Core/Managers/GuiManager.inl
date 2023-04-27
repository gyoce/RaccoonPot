#include <RP/Gui/GuiPanel.hpp>

template<class T, typename ...Args>
std::shared_ptr<T> RP::GuiManager::CreateWidget(Args&&... args) {
    std::shared_ptr<T> newWidget = std::make_shared<T>(std::forward<Args>(args)...);
    mainPanel->AddChild(newWidget);
    return newWidget;
}