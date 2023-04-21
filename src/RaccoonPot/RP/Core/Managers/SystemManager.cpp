#include "SystemManager.hpp"

#include "../Systems/System.hpp"

using namespace RP;

void SystemManager::EntityDestroyed(const Entity entity) const {
    for (const std::pair<const char* const, SystemPtr>& pair : systems) {
        const SystemPtr& system = pair.second;
        system->Entities.erase(entity);
    }
}

void SystemManager::EntitySignatureChanged(const Entity entity, const Signature entitySignature) {
    for (const std::pair<const char* const, SystemPtr>& pair : systems) {
        const char* const type = pair.first;
        const SystemPtr& system = pair.second;
        const Signature& systemSignature = signatures[type];
        if ((entitySignature & systemSignature) == systemSignature) {
            system->Entities.insert(entity);
        }
        else {
            system->Entities.erase(entity);
        }
    }
}