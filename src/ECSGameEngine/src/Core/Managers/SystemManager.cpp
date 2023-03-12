#include "SystemManager.hpp"

using namespace GameEngine;

void SystemManager::EntityDestroyed(Entity entity) {
    for (const std::pair<const char* const, std::shared_ptr<System>>& pair : systems) {
        const std::shared_ptr<System>& system = pair.second;
        system->Entities.erase(entity);
    }
}

void SystemManager::EntitySignatureChanged(Entity entity, Signature entitySignature) {
    for (const std::pair<const char* const, std::shared_ptr<System>>& pair : systems) {
        const char* const type = pair.first;
        const std::shared_ptr<System>& system = pair.second;
        const Signature& systemSignature = signatures[type];
        if ((entitySignature & systemSignature) == systemSignature) {
            system->Entities.insert(entity);
        }
        else {
            system->Entities.erase(entity);
        }
    }
}