#ifndef RP_SYSTEM_HPP
#define RP_SYSTEM_HPP

#include <set>

#include "../Types.hpp"

namespace RP {

    class System {
    public:
        std::set<Entity> Entities;
    };

}

#endif // RP_SYSTEM_HPP