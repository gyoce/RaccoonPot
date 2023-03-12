#include "ComponentManager.hpp"

using namespace ECSGameEngine;

void ComponentManager::EntityDestroyed(Entity entity) {
    for (const std::pair<const char*, const std::shared_ptr<IComponentArray>> pair : mapComponentArrays) {
        const std::shared_ptr<IComponentArray>& component = pair.second;
        component->EntityDestroyed(entity);
    }
}