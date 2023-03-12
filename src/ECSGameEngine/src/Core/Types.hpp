#ifndef TYPES_HPP
#define TYPES_HPP

#include <bitset>
#include <cstdint>

namespace GameEngine {
    const std::uint16_t MAX_ENTITIES = 5000;
    const std::uint8_t MAX_COMPONENTS = 32;

    using Entity = std::uint32_t;
    using ComponentType = std::uint8_t;
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif // TYPES_HPP