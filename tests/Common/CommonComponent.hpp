#ifndef TESTS_COMMON_COMPONENT_HPP
#define TESTS_COMMON_COMPONENT_HPP

struct ComponentTest {
    ComponentTest() = default;
    explicit ComponentTest(int x) : x(x) {  }
    int x;
};

#endif // TESTS_COMMON_COMPONENT_HPP