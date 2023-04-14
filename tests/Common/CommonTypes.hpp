#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <Core/Scene.hpp>
#include <Core/Systems/System.hpp>

struct ComponentTest {
    ComponentTest() = default;
    explicit ComponentTest(int x) : x(x) {  }
    int x;
};

class SystemTest : public ECSGameEngine::System {

};

class SceneTest : public ECSGameEngine::Scene {
public:
    SCENE_CONSTRUCTOR(SceneTest)

    inline static int LOOP_RETURN = 0;

    int Loop() override {
        return LOOP_RETURN;
    }
};

class SceneTest2 : public ECSGameEngine::Scene {
public:
    SCENE_CONSTRUCTOR(SceneTest2)

    inline static int LOOP_RETURN = 0;

    int Loop() override {
        return LOOP_RETURN;
    }
};

#endif // COMMON_TYPES_HPP