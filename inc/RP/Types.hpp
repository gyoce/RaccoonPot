#ifndef RP_TYPES_HPP
#define RP_TYPES_HPP

#include <bitset>
#include <cstdint>

namespace RP {

    constexpr std::uint16_t MaxEntities = 5000;
    constexpr std::uint8_t MaxComponents = 32;

    using Entity = std::uint32_t;
    using ComponentType = std::uint8_t;
    using Signature = std::bitset<MaxComponents>;

} // namespace RP

#endif // RP_TYPES_HPP