#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

#include <memory>

#include <Core/Types.hpp>
#include <Core/Managers/ComponentManager.hpp>
#include <Core/Managers/EntityManager.hpp>
#include <Core/Managers/SystemManager.hpp>

namespace ECSGameEngine {

    class Coordinator {
    public:
        Coordinator();

        Entity CreateEntity();
        void DestroyEntity(Entity entity);

        template<class T> void RegisterComponent();
        template<class T> void AddComponent(Entity entity, T component);
        template<class T> void RemoveComponent(Entity entity);
        template<class T> T& GetComponent(Entity entity);
        template<class T> ComponentType GetComponentType();

        template<class T> std::shared_ptr<T> RegisterSystem();
        template<class T> void SetSystemSignature(Signature signature);

    private:
        std::shared_ptr<ComponentManager> componentManager;
        std::shared_ptr<EntityManager> entityManager;
        std::shared_ptr<SystemManager> systemManager;
    };

}

#include "Coordinator.inl"

#endif // COORDINATOR_HPP