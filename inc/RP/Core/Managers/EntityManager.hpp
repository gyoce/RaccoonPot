#ifndef RP_ENTITY_MANAGER_HPP
#define RP_ENTITY_MANAGER_HPP

#include <queue>
#include <array>
#include <memory>

#include <RP/Types.hpp>

namespace RP {

    class EntityManager {
    public:
        EntityManager();
        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        [[nodiscard]] Signature GetSignature(Entity entity) const;

    private:
        std::queue<Entity> availableEntities{};
        std::array<Signature, MaxEntities> signatures{};
        std::uint32_t livingEntityCount{};
    };
    using EntityManagerPtr = std::shared_ptr<EntityManager>;

} // namespace RP

#endif // RP_ENTITY_MANAGER_HPP