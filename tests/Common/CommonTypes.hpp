#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <Core/Scene.hpp>
#include <Core/Systems/System.hpp>

struct ComponentTest {
    ComponentTest() = default;
    explicit ComponentTest(int x) : x(x) {  }
    int x;
};

class SystemTest : public EcsGameEngine::System {

};

class SceneTest : public EcsGameEngine::Scene {
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

class SceneTest2 : public EcsGameEngine::Scene {
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