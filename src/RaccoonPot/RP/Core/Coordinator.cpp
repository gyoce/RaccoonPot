#include "RP/Core/Coordinator.hpp"

#include "RP/Core/Managers/ComponentManager.hpp"
#include "RP/Core/Managers/EntityManager.hpp"
#include "RP/Core/Managers/SystemManager.hpp"

namespace RP
{

Coordinator::Coordinator() {
    componentManager = std::make_shared<ComponentManager>();
    entityManager = std::make_shared<EntityManager>();
    systemManager = std::make_shared<SystemManager>();
}

Entity Coordinator::CreateEntity() const {
    return entityManager->CreateEntity();
}

void Coordinator::DestroyEntity(const Entity entity) const {
    entityManager->DestroyEntity(entity);
    componentManager->EntityDestroyed(entity);
    systemManager->EntityDestroyed(entity);
}

}