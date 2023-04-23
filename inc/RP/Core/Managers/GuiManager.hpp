#ifndef RP_GUI_MANAGER_HPP
#define RP_GUI_MANAGER_HPP

#include <memory>
#include <vector>

#include <RP/Core/Managers/EventManager.hpp>
#include <RP/Types.hpp>

namespace RP {

    class GuiManager {
    public:
        void RegisterEventManager(const EventManagerPtr& eventManager);
        template<class T> void RegisterRenderFunctionForWidget(std::function<void(std::shared_ptr<T>)> function);
        void RegisterClickEvent(int event) const;
        template<class T, typename ...Args> std::shared_ptr<T> CreateWidget(Args&&... args);
        void Render() const;

    private:
        class IWidgetFunction { 
        public:
            virtual ~IWidgetFunction() = default;
            virtual void RenderWidgets() const = 0;
            std::vector<GuiWidgetPtr> Widgets{};
        };
        typedef std::shared_ptr<IWidgetFunction> IWidgetFunctionPtr;

        template<class T>
        class WidgetFunction final : public IWidgetFunction {
        public:
            void RenderWidgets() const override;

            std::function<void(std::shared_ptr<T>)> RenderFunction;
        };

        void checkForClickOnWidgetButton(int x, int y) const;

        EventManagerPtr eventManager = nullptr;
        std::unordered_map<const char*, IWidgetFunctionPtr> mapWidgets;
    };

}

#include <RP/Core/Managers/GuiManager.inl>

#endif // RP_GUI_MANAGER_HPP