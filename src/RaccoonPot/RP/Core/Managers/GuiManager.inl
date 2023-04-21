#include "GuiManager.hpp"

template<class T>
void RP::GuiManager::RegisterRenderFunctionForWidget(std::function<void(std::shared_ptr<T>)> function) {
    const char* type = typeid(T).name();
    assert(mapWidgets.find(type) == mapWidgets.end() && "Widget already registered.");
    std::shared_ptr<WidgetFunction<T>> widgetFunction = std::make_shared<WidgetFunction<T>>();
    widgetFunction->RenderFunction = function;
    mapWidgets.insert({ type, widgetFunction });
}

template<class T, typename ...Args>
std::shared_ptr<T> RP::GuiManager::CreateWidget(Args&&... args) {
    const char* type = typeid(T).name();
    assert(mapWidgets.find(type) != mapWidgets.end() && "Widget didn't registered before use.");
    std::shared_ptr<WidgetFunction<T>> widgetFunction = std::static_pointer_cast<WidgetFunction<T>>(mapWidgets[type]);
    std::shared_ptr<T> newWidget = std::make_shared<T>(std::forward<Args>(args)...);
    widgetFunction->Widgets.push_back(newWidget);
    return newWidget;
}

template<class T>
void RP::GuiManager::WidgetFunction<T>::RenderWidgets() const {
    for (const std::shared_ptr<GuiWidget>& widget : Widgets) {
        RenderFunction(std::static_pointer_cast<T>(widget));
    }
}