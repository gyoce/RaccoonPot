#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

#include <memory>

#include <Core/Types.hpp>
#include <Core/Managers/ComponentManager.hpp>
#include <Core/Managers/EntityManager.hpp>
#include <Core/Managers/SystemManager.hpp>

namespace EcsGameEngine {

    class Coordinator {
    public:
        Coordinator();

        Entity CreateEntity() const;
        void DestroyEntity(Entity entity) const;

        template<class T> void RegisterComponent() const;
        template<class T> void AddComponent(Entity entity, T component);
        template<class T> void RemoveComponent(Entity entity) const;
        template<class T> T& GetComponent(Entity entity);
        template<class T> ComponentType GetComponentType() const;

        template<class T> std::shared_ptr<T> RegisterSystem();
        template<class T> void SetSystemSignature(Signature signature) const;

    private:
        std::shared_ptr<ComponentManager> componentManager;
        std::shared_ptr<EntityManager> entityManager;
        std::shared_ptr<SystemManager> systemManager;
    };

}

#include "Coordinator.inl"

#endif // COORDINATOR_HPP