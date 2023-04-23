#include "RP/Core/Managers/ComponentManager.hpp"

using namespace RP;

void ComponentManager::EntityDestroyed(const Entity entity) const {
    for (const std::pair<const char*, const IComponentArrayPtr> pair : mapComponentArrays) {
        pair.second->EntityDestroyed(entity);
    }
}
