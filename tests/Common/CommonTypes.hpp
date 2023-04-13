#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <Core/Scene.hpp>
#include <Core/Systems/System.hpp>

struct ComponentTest {
    ComponentTest() = default;
    ComponentTest(int x) : x(x) {  }
    int x;
};

class SystemTest : public ECSGameEngine::System {

};

class SceneTest : public ECSGameEngine::Scene {
public:
    inline static int LOOP_RETURN = 0;

    SceneTest(std::unique_ptr<Coordinator> coord) : Scene(std::move(coord)) {  }

    int Loop() override {
        return LOOP_RETURN;
    }
};

class SceneTest2 : public ECSGameEngine::Scene {
public:
    inline static int LOOP_RETURN = 0;

    SceneTest2(std::unique_ptr<Coordinator> coord) : Scene(std::move(coord)) {  }

    int Loop() override {
        return LOOP_RETURN;
    }
};

#endif // COMMON_TYPES_HPP