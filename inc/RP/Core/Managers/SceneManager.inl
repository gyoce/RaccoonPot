#include <algorithm>
#include <cassert>

template<class T, typename ...Args>
std::shared_ptr<T> RP::SceneManager::RegisterScene(int action, Args&&... args) {
    const char* sceneName = typeid(T).name();
    assert(!sceneAlreadyPresent(sceneName) && "Scene already present.");
    assert(!scenes.contains(action) && "Scene action already present.");
    std::shared_ptr<T> scene = std::make_shared<T>(renderer, std::forward<Args>(args)...);
    scenes.insert({ action, std::make_tuple(sceneName, scene) });
    return scene;
}