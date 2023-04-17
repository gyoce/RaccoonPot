#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <functional>

namespace RP {

    class EventManager {
    public:
        template<typename T> void Bind(int event, const std::function<T>& callback);
        template<typename T, class... Args> void Dispatch(int event, Args... args);

    private:
        class IEventFunction {
        public:
            virtual ~IEventFunction() = default;
        };

        template<class T>
        class EventFunction final : public IEventFunction {
        public:
            void Add(std::function<T> function) { Functions.push_back(function); }
            std::vector<std::function<T>> Functions{};
        };

        std::unordered_map<int, std::shared_ptr<IEventFunction>> eventFunctions{};
    };

}

#include "EventManager.inl"

#endif // EVENT_MANAGER_HPP