#include "RP/Core/Managers/EntityManager.hpp"

#include <cassert>

namespace RP
{
 
EntityManager::EntityManager() {
    for (Entity entity = 0; entity < MaxEntities; entity++) {
        availableEntities.push(entity);
    }
}

Entity EntityManager::CreateEntity() {
    assert(livingEntityCount < MaxEntities && "Too many entities in existence.");
    const Entity id = availableEntities.front();
    availableEntities.pop();
    livingEntityCount++;
    return id;
}

void EntityManager::DestroyEntity(const Entity entity) {
    assert(entity < MaxEntities && "Entity out of range.");
    signatures[entity].reset();
    availableEntities.push(entity);
    livingEntityCount--;
}

void EntityManager::SetSignature(const Entity entity, const Signature signature) {
    assert(entity < MaxEntities && "Entity out of range.");
    signatures[entity] = signature;
}

Signature EntityManager::GetSignature(const Entity entity) const {
    assert(entity < MaxEntities && "Entity out of range.");
    return signatures[entity];
}

} // namespace RP