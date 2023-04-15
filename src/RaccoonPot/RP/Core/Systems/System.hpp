#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <set>

#include "../Types.hpp"

namespace RP {

    class System {
    public:
        std::set<Entity> Entities;
    };

}

#endif // SYSTEM_HPP