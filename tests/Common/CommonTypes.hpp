#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

struct ComponentTest {
    ComponentTest() = default;
    ComponentTest(int x) : x(x) {  }
    int x;
};

#endif // COMMON_TYPES_HPP