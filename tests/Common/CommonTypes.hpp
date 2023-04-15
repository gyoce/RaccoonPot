#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <RP/Core/Scene.hpp>
#include <RP/Core/Systems/System.hpp>

struct ComponentTest {
    ComponentTest() = default;
    explicit ComponentTest(int x) : x(x) {  }
    int x;
};

class SystemTest : public RP::System {

};

class SceneTest : public RP::Scene {
public:
    SCENE_CONSTRUCTOR(SceneTest)

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
    SCENE_CONSTRUCTOR(SceneTest2)

    void SetLoopReturn(const int newLoopReturn) {
        loopReturn = newLoopReturn;
    }

    int Loop() override {
        return loopReturn;
    }

private:
    int loopReturn = 0;
};

#endif // COMMON_TYPES_HPP