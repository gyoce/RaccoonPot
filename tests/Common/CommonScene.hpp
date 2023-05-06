#ifndef TESTS_COMMON_SCENE_HPP
#define TESTS_COMMON_SCENE_HPP

class SceneTest final : public RP::Scene {
public:
    RP_SCENE_CONSTRUCTOR(SceneTest) {  }

    void SetLoopReturn(const int newLoopReturn) {
        loopReturn = newLoopReturn;
    }

    int Loop() override {
        return loopReturn;
    }

private:
    int loopReturn = 0;
};

class SceneTest2 final : public RP::Scene {
public:
    RP_SCENE_CONSTRUCTOR(SceneTest2) {  }

    void SetLoopReturn(const int newLoopReturn) {
        loopReturn = newLoopReturn;
    }

    int Loop() override {
        return loopReturn;
    }

private:
    int loopReturn = 0;
};

#endif // TESTS_COMMON_SCENE_HPP