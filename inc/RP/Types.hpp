#ifndef RP_TYPES_HPP
#define RP_TYPES_HPP

#include <bitset>
#include <cstdint>
#include <memory>

namespace RP {
    constexpr std::uint16_t MaxEntities = 5000;
    constexpr std::uint8_t MaxComponents = 32;

    using Entity = std::uint32_t;
    using ComponentType = std::uint8_t;
    using Signature = std::bitset<MaxComponents>;

    class ComponentManager;
    using ComponentManagerPtr = std::shared_ptr<ComponentManager>;

    class Coordinator;
    using CoordinatorPtr = std::shared_ptr<Coordinator>;

    class EntityManager;
    using EntityManagerPtr = std::shared_ptr<EntityManager>;

    class EventManager;
    using EventManagerPtr = std::shared_ptr<EventManager>;

    class Font;
    using FontPtr = std::shared_ptr<Font>;

    class GuiButton;
    using GuiButtonPtr = std::shared_ptr<GuiButton>;

    class GuiButtonTexture;
    using GuiButtonTexturePtr = std::shared_ptr<GuiButtonTexture>;

    class GuiManager;
    using GuiManagerPtr = std::shared_ptr<GuiManager>;

    class GuiWidget;
    using GuiWidgetPtr = std::shared_ptr<GuiWidget>;

    class ResourceManager;
    using ResourceManagerPtr = std::shared_ptr<ResourceManager>;

    class Scene;
    using ScenePtr = std::shared_ptr<Scene>;

    class SceneManager;
    using SceneManagerPtr = std::shared_ptr<SceneManager>;

    class SpriteSheet;
    using SpriteSheetPtr = std::shared_ptr<SpriteSheet>;

    class System;
    using SystemPtr = std::shared_ptr<System>;

    class SystemManager;
    using SystemManagerPtr = std::shared_ptr<SystemManager>;

    class WindowManager;
    using WindowManagerPtr = std::shared_ptr<WindowManager>;
}

#endif // RP_TYPES_HPP