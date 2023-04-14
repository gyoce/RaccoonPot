#include "SceneManager.hpp"

#include <algorithm>

namespace EcsGameEngine {

    template<class T>
    std::shared_ptr<T> SceneManager::RegisterScene(int action) {
        assert(std::find(sceneNames.begin(), sceneNames.end(), typeid(T).name()) == sceneNames.end() && "Scene already present.");
        assert(scenes.find(action) == scenes.end() && "Scene action already present.");
        std::shared_ptr<T> scene = std::make_shared<T>(std::make_unique<Coordinator>());
        scenes.insert({ action, scene });
        sceneNames.push_back(typeid(T).name());
        return scene;
    }

}