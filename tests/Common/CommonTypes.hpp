#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <Core/Systems/System.hpp>

struct ComponentTest {
    ComponentTest() = default;
    ComponentTest(int x) : x(x) {  }
    int x;
};

class SystemTest : public GameEngine::System {

};

#endif // COMMON_TYPES_HPP