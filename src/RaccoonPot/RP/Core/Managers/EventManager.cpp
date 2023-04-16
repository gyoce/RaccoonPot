#include "EventManager.hpp"

#include <cassert>

void RP::EventManager::Bind(int event, const std::function<void()>& callback) {
     if (callbacks.find(event) == callbacks.end()) {
         std::vector<std::function<void()>> vector{};
         vector.push_back(callback);
         callbacks.insert({ event, vector });
     } else {
         callbacks[event].push_back(callback);
     }
}

void RP::EventManager::Dispatch(const int event) {
    assert(callbacks.find(event) != callbacks.end() && "Event didn't bind.");
    for (const std::function<void()>& callback : callbacks[event]) {
        callback();
    }
}
