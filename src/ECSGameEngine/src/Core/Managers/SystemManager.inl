#include "SystemManager.hpp"

#include <cassert>

namespace EcsGameEngine {

    template<class T>
    std::shared_ptr<T> SystemManager::RegisterSystem() {
        const char* typeName = typeid(T).name();
        assert(systems.find(typeName) == systems.end() && "Registering system more than once.");
        std::shared_ptr<T> system = std::make_shared<T>();
        systems.insert({ typeName, system });
        return system;
    }

    template<class T>
    void SystemManager::SetSignature(Signature signature) {
        const char* typeName = typeid(T).name();
        assert(systems.find(typeName) != systems.end() && "System used before registered.");
        signatures.insert({ typeName, signature });
    }

}