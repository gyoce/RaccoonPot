#include "Coordinator.hpp"

using namespace ECSGameEngine;

Coordinator::Coordinator() {
    componentManager = std::make_shared<ComponentManager>();
    entityManager = std::make_shared<EntityManager>();
    systemManager = std::make_shared<SystemManager>();
}

Entity Coordinator::CreateEntity() {
    return entityManager->CreateEntity();
}

void Coordinator::DestroyEntity(Entity entity) {
    entityManager->DestroyEntity(entity);
    componentManager->EntityDestroyed(entity);
    systemManager->EntityDestroyed(entity);
}