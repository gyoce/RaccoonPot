#ifndef RP_SYSTEM_HPP
#define RP_SYSTEM_HPP

#include <set>
#include <memory>

#include <RP/Types.hpp>

namespace RP {

    class System {
    public:
        std::set<Entity> Entities;
    };
    using SystemPtr = std::shared_ptr<System>;

} // namespace RP

#endif // RP_SYSTEM_HPP