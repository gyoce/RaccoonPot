#include "SceneManager.hpp"

#include <algorithm>

using namespace ECSGameEngine;

template<class T>
void SceneManager::RegisterScene(int action) {
    assert(std::find(sceneNames.begin(), sceneNames.end(), typeid(T).name()) == sceneNames.end() && "Scene already present.");
    assert(scenes.find(action) == scenes.end() && "Scene action already present.");
    std::shared_ptr<Scene> scene = std::make_shared<T>(std::unique_ptr<Coordinator>(new Coordinator));
    scenes.insert( {action, scene} );
    sceneNames.push_back(typeid(T).name());
}