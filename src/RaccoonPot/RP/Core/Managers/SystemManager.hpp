#ifndef RP_SYSTEM_MANAGER_HPP
#define RP_SYSTEM_MANAGER_HPP

#include <unordered_map>
#include <memory>

#include "../Types.hpp"

namespace RP {

    class SystemManager {
    public:
        template<class T> std::shared_ptr<T> RegisterSystem();
        template<class T> void SetSignature(Signature signature);
        void EntityDestroyed(Entity entity) const;
        void EntitySignatureChanged(Entity entity, Signature entitySignature);

    private:
        std::unordered_map<const char*, SystemPtr> systems{};
        std::unordered_map<const char*, Signature> signatures{};
    };

}

#include "SystemManager.inl"

#endif // RP_SYSTEM_MANAGER_HPP