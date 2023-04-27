#include <algorithm>
#include <cassert>

template<class T, typename ...Args>
std::shared_ptr<T> RP::SceneManager::RegisterScene(int action, Args&&... args) {
    assert(std::find(sceneNames.begin(), sceneNames.end(), typeid(T).name()) == sceneNames.end() && "Scene already present.");
    assert(scenes.find(action) == scenes.end() && "Scene action already present.");
    std::shared_ptr<T> scene = std::make_shared<T>(std::forward<Args>(args)...);
    scene->SetRenderer(renderer);
    scenes.insert({ action, scene });
    sceneNames.push_back(typeid(T).name());
    return scene;
}