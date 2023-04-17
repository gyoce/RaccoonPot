#include "EventManager.hpp"

#include <cassert>

template<typename T>
void RP::EventManager::Bind(int event, const std::function<T>& callback) {
    if (eventFunctions.find(event) == eventFunctions.end()) {
        std::shared_ptr<EventFunction<T>> eventFunction = std::make_shared<EventFunction<T>>();
        eventFunction->Add(callback);
        eventFunctions.insert({ event,  eventFunction });
    } else {
        std::shared_ptr<EventFunction<T>> eventFunction = std::static_pointer_cast<EventFunction<T>>(eventFunctions[event]);
        eventFunction->Add(callback);
    }
}

template<typename T, class... Args>
void RP::EventManager::Dispatch(const int event, Args... args) {
    assert(eventFunctions.find(event) != eventFunctions.end() && "Event didn't bind.");
    std::shared_ptr<EventFunction<T>> eventFunction = std::static_pointer_cast<EventFunction<T>>(eventFunctions[event]);
    std::vector<std::function<T>>& functions = eventFunction->Functions;
    for (const auto& callback : functions) {
        callback(std::forward<Args>(args)...);
    }
}
