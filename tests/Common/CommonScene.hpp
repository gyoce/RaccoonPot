#ifndef TESTS_COMMON_SCENE_HPP
#define TESTS_COMMON_SCENE_HPP

class SceneTest: public RP::Scene {
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

class SceneTest2: public RP::Scene {
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

#endif // TESTS_COMMON_SCENE_HPP