#include "Coordinator.hpp"

using namespace RP;

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
