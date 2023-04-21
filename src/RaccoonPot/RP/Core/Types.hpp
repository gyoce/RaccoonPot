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

    class EventManager;
    typedef std::shared_ptr<EventManager> EventManagerPtr;

    class GuiManager;
    typedef std::shared_ptr<GuiManager> GuiManagerPtr;
}

#endif // RP_TYPES_HPP