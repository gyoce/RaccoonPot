#ifndef RP_EVENT_MANAGER_HPP
#define RP_EVENT_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <functional>

#include <RP/RPMacros.hpp>

namespace RP {

    class EventManager {
    public:
        template<typename T> void Bind(int event, const std::function<T>& callback);
        template<typename T, class... Args> void Dispatch(int event, Args&&... args);

    private:
        class IEventFunction {
        public:
            IEventFunction() = default;
            virtual ~IEventFunction() = default;
            RP_DELETE_MISC_CONSTRUCTORS(IEventFunction)
        };
        typedef std::shared_ptr<IEventFunction> IEventFunctionPtr;

        template<class T>
        class EventFunction final : public IEventFunction {
        public:
            std::vector<std::function<T>> Functions{};
        };

        std::unordered_map<int, IEventFunctionPtr> eventFunctions{};
    };

} // namespace RP

#include <RP/Core/Managers/EventManager.inl>

#endif // RP_EVENT_MANAGER_HPP