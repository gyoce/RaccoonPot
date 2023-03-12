#ifndef COMPONENT_ARRAY_HPP
#define COMPONENT_ARRAY_HPP

#include <array>
#include <unordered_map>

#include "Core/Types.hpp"

namespace GameEngine {

    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(Entity entity) = 0;
    };

    template<class T>
    class ComponentArray : public IComponentArray {
    public:
        void InsertData(Entity entity, T component);
        void RemoveData(Entity entity);
        T& GetData(Entity entity);
        void EntityDestroyed(Entity entity) override;

    private:
        std::array<T, MAX_ENTITIES> componentArray{};
        std::unordered_map<Entity, size_t> entityToIndexMap{};
        std::unordered_map<size_t, Entity> indexToEntityMap{};
        size_t size{};

        void putNewEntryAtTheEnd(Entity entity, T component);
        void copyElementAtEnd(size_t indexOfRemovedEntity, size_t indexOfLastElement);
        void updateMapToMovedSpot(size_t indexOfRemovedEntity, size_t indexOfLastElement);
    };

}

#include "ComponentArray.inl"

#endif // COMPONENT_ARRAY_HPP