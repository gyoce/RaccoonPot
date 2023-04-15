#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <unordered_map>
#include <memory>

#include "../Systems/System.hpp"
#include "../Types.hpp"

namespace RP {

    class SystemManager {
    public:
        template<class T> std::shared_ptr<T> RegisterSystem();
        template<class T> void SetSignature(Signature signature);
        void EntityDestroyed(Entity entity) const;
        void EntitySignatureChanged(Entity entity, Signature entitySignature);

    private:
        std::unordered_map<const char*, std::shared_ptr<System>> systems{};
        std::unordered_map<const char*, Signature> signatures{};
    };

}

#include "SystemManager.inl"

#endif // SYSTEM_MANAGER_HPP