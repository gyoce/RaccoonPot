#ifndef RP_TYPES_HPP
#define RP_TYPES_HPP

#include <bitset>
#include <cstdint>
#include <memory>

namespace RP {
    constexpr std::uint16_t MAX_ENTITIES = 5000;
    constexpr std::uint8_t MAX_COMPONENTS = 32;

    using Entity = std::uint32_t;
    using ComponentType = std::uint8_t;
    using Signature = std::bitset<MAX_COMPONENTS>;

    // #################### TYPEDEF #################### //

    class ComponentManager;
    typedef std::shared_ptr<ComponentManager> ComponentManagerPtr;

    class Coordinator;
    typedef std::shared_ptr<Coordinator> CoordinatorPtr;

    class EntityManager;
    typedef std::shared_ptr<EntityManager> EntityManagerPtr;

    class EventManager;
    typedef std::shared_ptr<EventManager> EventManagerPtr;

    class GuiButton;
    typedef std::shared_ptr<GuiButton> GuiButtonPtr;

    class GuiManager;
    typedef std::shared_ptr<GuiManager> GuiManagerPtr;

    class GuiWidget;
    typedef std::shared_ptr<GuiWidget> GuiWidgetPtr;

    class Scene;
    typedef std::shared_ptr<Scene> ScenePtr;

    class System;
    typedef std::shared_ptr<System> SystemPtr;

    class SystemManager;
    typedef std::shared_ptr<SystemManager> SystemManagerPtr;
}

#endif // RP_TYPES_HPP