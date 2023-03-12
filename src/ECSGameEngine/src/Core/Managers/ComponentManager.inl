#include "ComponentManager.hpp"

#include <cassert>

using namespace ECSGameEngine;

template<class T>
void ComponentManager::RegisterComponent() {
    const char* typeName = typeid(T).name();
    assert(mapComponentTypes.find(typeName) == mapComponentTypes.end() && "Registering component type more than once");
    mapComponentTypes.insert( {typeName, nextComponentType} );
    mapComponentArrays.insert( {typeName, std::make_shared<ComponentArray<T>>()} );
    nextComponentType++;
}

template<class T>
ComponentType ComponentManager::GetComponentType() {
    const char* typeName = typeid(T).name();
    assert(mapComponentTypes.find(typeName) != mapComponentTypes.end() && "Component not registered before use");
    return mapComponentTypes[typeName];
}

template<class T>
void ComponentManager::AddComponent(Entity entity, T component) {
    getComponentArray<T>()->InsertData(entity, component);
}

template<class T>
void ComponentManager::RemoveComponent(Entity entity) {
    getComponentArray<T>()->RemoveData(entity);
}

template<class T>
T& ComponentManager::GetComponent(Entity entity) {
    return getComponentArray<T>()->GetData(entity);
}

template<class T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray() {
    const char* typeName = typeid(T).name();
    assert(mapComponentTypes.find(typeName) != mapComponentTypes.end() && "Component not registered before use");
    return std::static_pointer_cast<ComponentArray<T>>(mapComponentArrays[typeName]);
}