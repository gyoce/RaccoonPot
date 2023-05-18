#ifndef RP_COMPONENT_MANAGER_HPP
#define RP_COMPONENT_MANAGER_HPP

#include <unordered_map>
#include <memory>

#include <RP/Types.hpp>
#include <RP/Core/Components/ComponentArray.hpp>

namespace RP {

    class ComponentManager {
    public:
        template<class T> void RegisterComponent();
        template<class T> ComponentType GetComponentType();
        template<class T> void AddComponent(Entity entity, T component);
        template<class T> void RemoveComponent(Entity entity);
        template<class T> T& GetComponent(Entity entity);

        void EntityDestroyed(Entity entity) const;

    private:
        template<class T> std::shared_ptr<ComponentArray<T>> getComponentArray();

        std::unordered_map<const char*, ComponentType> mapComponentTypes{};
        std::unordered_map<const char*, IComponentArrayPtr> mapComponentArrays{};
        ComponentType nextComponentType{};
    };
    using ComponentManagerPtr = std::shared_ptr<ComponentManager>;

} // namespace RP

#include <RP/Core/Managers/ComponentManager.inl>

#endif // RP_COMPONENT_MANAGER_HPP