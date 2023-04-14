#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <set>

#include <Core/Types.hpp>

namespace EcsGameEngine {

    class System {
    public:
        std::set<Entity> Entities;
    };

}

#endif // SYSTEM_HPP