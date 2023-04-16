#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <functional>

namespace RP {

    class EventManager {
    public:
        void Bind(int event, const std::function<void()>& callback);
        void Dispatch(int event);

    private:
        std::unordered_map<int, std::vector<std::function<void()>>> callbacks{};
    };

}

#endif // EVENT_MANAGER_HPP