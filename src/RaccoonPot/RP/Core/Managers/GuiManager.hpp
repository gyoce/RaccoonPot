#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include <memory>
#include <vector>

#include "EventManager.hpp"
#include "../../Gui/GuiWidget.hpp"

namespace RP {

    class GuiManager {
    public:
        void RegisterEventManager(const std::shared_ptr<EventManager>& eventManager);
        template<class T> void RegisterRenderFunctionForWidget(std::function<void(std::shared_ptr<T>)> function);
        void RegisterClickEvent(int event) const;
        template<class T, typename ...Args> std::shared_ptr<T> CreateWidget(Args&&... args);
        void Render() const;

    private:
        class IWidgetFunction {
        public:
            virtual ~IWidgetFunction() = default;
            virtual void RenderWidgets() const = 0;
            std::vector<std::shared_ptr<GuiWidget>> Widgets{};
        };

        template<class T>
        class WidgetFunction final : public IWidgetFunction {
        public:
            void RenderWidgets() const override;

            std::function<void(std::shared_ptr<T>)> RenderFunction;
        };

        void checkForClickOnWidgetButton(int x, int y) const;

        std::shared_ptr<EventManager> eventManager = nullptr;
        std::unordered_map<const char*, std::shared_ptr<IWidgetFunction>> mapWidgets;
    };

}

#include "GuiManager.inl"

#endif // GUI_MANAGER_HPP