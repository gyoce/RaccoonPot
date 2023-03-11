#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <queue>
#include <array>

#include <Core/Types.hpp>

namespace GameEngine {

    class EntityManager {
    public:
        EntityManager();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity);

    private:
        std::queue<Entity> availableEntities{};
        std::array<Signature, MAX_ENTITIES> signatures{};
        std::uint32_t livingEntityCount{};
    };

}

#endif // ENTITY_MANAGER_HPP