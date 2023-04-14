#include "ComponentManager.hpp"

using namespace EcsGameEngine;

void ComponentManager::EntityDestroyed(const Entity entity) const {
    for (const std::pair<const char*, const std::shared_ptr<IComponentArray>> pair : mapComponentArrays) {
        const std::shared_ptr<IComponentArray>& component = pair.second;
        component->EntityDestroyed(entity);
    }
}
