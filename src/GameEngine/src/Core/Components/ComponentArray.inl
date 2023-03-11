#include "ComponentArray.hpp"

#include <cassert>

using namespace GameEngine;

template<class T>
void ComponentArray<T>::InsertData(Entity entity, T component) {
    assert(entityToIndexMap.find(entity) == entityToIndexMap.end() && "Component added to same entity more than once.");
    putNewEntryAtTheEnd(entity, component);
}

template<class T>
void ComponentArray<T>::RemoveData(Entity entity) {
    assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Removing non-existent component.");
    size_t indexOfRemovedEntity = entityToIndexMap[entity];
    size_t indexOfLastElement = size - 1;
    copyElementAtEnd(indexOfRemovedEntity, indexOfLastElement);
    updateMapToMovedSpot(indexOfRemovedEntity, indexOfLastElement);
    entityToIndexMap.erase(entity);
    indexToEntityMap.erase(indexOfLastElement);
    size--;
}

template<class T>
void ComponentArray<T>::updateMapToMovedSpot(size_t indexOfRemovedEntity, size_t indexOfLastElement) {
    Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
    entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;
}

template<class T>
void ComponentArray<T>::copyElementAtEnd(size_t indexOfRemovedEntity, size_t indexOfLastElement) {
    componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];
}

template<class T>
T& ComponentArray<T>::GetData(Entity entity) {
    assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Retrieving non-existent component.");
    return componentArray[entityToIndexMap[entity]];
}

template<class T>
void ComponentArray<T>::EntityDestroyed(Entity entity) {
    if (entityToIndexMap.find(entity) != entityToIndexMap.end()) {
        RemoveData(entity);
    }
}

template<class T>
void ComponentArray<T>::putNewEntryAtTheEnd(Entity entity, T component) {
    size_t newIndex = size;
    entityToIndexMap[entity] = newIndex;
    indexToEntityMap[newIndex] = entity;
    componentArray[newIndex] = component;
    size++;
}