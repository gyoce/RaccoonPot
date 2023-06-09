#ifndef RP_COORDINATOR_HPP
#define RP_COORDINATOR_HPP

#include <memory>

#include <RP/Types.hpp>
#include <RP/Core/Managers/ComponentManager.hpp>
#include <RP/Core/Managers/EntityManager.hpp>
#include <RP/Core/Managers/SystemManager.hpp>

namespace RP {

    class Coordinator {
    public:
        Coordinator();

        [[nodiscard]] Entity CreateEntity() const;
        void DestroyEntity(Entity entity) const;

        template<class T> void RegisterComponent() const;
        template<class T> void AddComponent(Entity entity, T component);
        template<class T> void RemoveComponent(Entity entity) const;
        template<class T> T& GetComponent(Entity entity);
        template<class T> [[nodiscard]] ComponentType GetComponentType() const;

        template<class T> std::shared_ptr<T> RegisterSystem();
        template<class T> void SetSystemSignature(Signature signature) const;

    private:
        ComponentManagerPtr componentManager;
        EntityManagerPtr entityManager;
        SystemManagerPtr systemManager;
    };
    using CoordinatorPtr = std::shared_ptr<Coordinator>;

} // namespace RP

#include <RP/Core/Coordinator.inl>

#endif // RP_COORDINATOR_HPP