#include <cassert>

template<class T>
void RP::ComponentArray<T>::InsertData(const Entity entity, T component) {
    assert(entityToIndexMap.find(entity) == entityToIndexMap.end() && "Component added to same entity more than once.");
    putNewEntryAtTheEnd(entity, component);
}

template<class T>
void RP::ComponentArray<T>::RemoveData(const Entity entity) {
    assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Removing non-existent component.");
    const size_t indexOfRemovedEntity = entityToIndexMap[entity];
    const size_t indexOfLastElement = size - 1;
    copyElementAtEnd(indexOfRemovedEntity, indexOfLastElement);
    updateMapToMovedSpot(indexOfRemovedEntity, indexOfLastElement);
    entityToIndexMap.erase(entity);
    indexToEntityMap.erase(indexOfLastElement);
    size--;
}

template<class T>
void RP::ComponentArray<T>::updateMapToMovedSpot(const size_t indexOfRemovedEntity, const size_t indexOfLastElement) {
    const Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
    entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
    indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;
}

template<class T>
void RP::ComponentArray<T>::copyElementAtEnd(size_t indexOfRemovedEntity, size_t indexOfLastElement) {
    componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];
}

template<class T>
T& RP::ComponentArray<T>::GetData(const Entity entity) {
    assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Retrieving non-existent component.");
    return componentArray[entityToIndexMap[entity]];
}

template<class T>
void RP::ComponentArray<T>::EntityDestroyed(const Entity entity) {
    if (entityToIndexMap.find(entity) != entityToIndexMap.end()) {
        RemoveData(entity);
    }
}

template<class T>
void RP::ComponentArray<T>::putNewEntryAtTheEnd(const Entity entity, T component) {
    size_t newIndex = size;
    entityToIndexMap[entity] = newIndex;
    indexToEntityMap[newIndex] = entity;
    componentArray[newIndex] = component;
    size++;
}