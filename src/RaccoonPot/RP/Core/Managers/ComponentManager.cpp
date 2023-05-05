#include "RP/Core/Managers/ComponentManager.hpp"

namespace RP
{

void ComponentManager::EntityDestroyed(const Entity entity) const {
    for (const std::pair<const char*, const IComponentArrayPtr> pair : mapComponentArrays) {
        pair.second->EntityDestroyed(entity);
    }
}

}