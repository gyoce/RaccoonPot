#ifndef RP_ENTITY_MANAGER_HPP
#define RP_ENTITY_MANAGER_HPP

#include <queue>
#include <array>

#include <RP/Types.hpp>

namespace RP {

    class EntityManager {
    public:
        EntityManager();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity) const;

    private:
        std::queue<Entity> availableEntities{};
        std::array<Signature, MAX_ENTITIES> signatures{};
        std::uint32_t livingEntityCount{};
    };

}

#endif // RP_ENTITY_MANAGER_HPP