#ifndef TESTS_COMMON_TYPES_HPP
#define TESTS_COMMON_TYPES_HPP

#include <RP/RP.hpp>

struct ComponentTest {
    ComponentTest() = default;
    explicit ComponentTest(int x) : x(x) {  }
    int x;
};

class SystemTest : public RP::System {

};

class SceneTest : public RP::Scene {
public:
    void SetLoopReturn(const int newLoopReturn) {
        loopReturn = newLoopReturn;
    }

    int Loop() override {
        return loopReturn;
    }

private:
    int loopReturn = 0;
};

class SceneTest2 : public RP::Scene {
public:
    void SetLoopReturn(const int newLoopReturn) {
        loopReturn = newLoopReturn;
    }

    int Loop() override {
        return loopReturn;
    }

private:
    int loopReturn = 0;
};

class WidgetTest : public RP::GuiButton {
public:
    WidgetTest() = default;
    WidgetTest(int value) : value(value) {  }

    bool CallRenderFunction = false;
    bool CallClickFunction = false;
    int value = 0;

    void Click() override {
        CallClickFunction = true;
    }
};

#endif // TESTS_COMMON_TYPES_HPP