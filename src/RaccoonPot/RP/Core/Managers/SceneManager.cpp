#include "RP/Core/Managers/SceneManager.hpp"

#include "RP/Core/Scene.hpp"
#include "RP/Logs/Log.hpp"

using namespace RP;

SceneManager::SceneManager(SDL_Renderer* renderer)
    : renderer(renderer) {  }

int SceneManager::Loop() {
    assert(scenes.contains(baseAction) && "Scene with base action not present.");
    ScenePtr actualScene = std::get<ScenePtr>(scenes[baseAction]);
    const char* actualSceneName = std::get<const char*>(scenes[baseAction]);
    Log("First scene: {}", actualSceneName);
    int loopRes = actualScene->Loop();
    while (scenes.contains(loopRes)) {
        Log("Change of scene from {} to {}", actualSceneName, std::get<const char*>(scenes[loopRes]));
        actualScene = std::get<ScenePtr>(scenes[loopRes]);
        actualSceneName = std::get<const char*>(scenes[loopRes]);
        loopRes = actualScene->Loop();
    }
    return loopRes;
}

void SceneManager::SetBaseAction(const int baseAction) {
    this->baseAction = baseAction;
}

bool SceneManager::sceneAlreadyPresent(const char* sceneName) const {
    for (std::pair<const int, std::tuple<const char*, ScenePtr>> const& scene : scenes) {
        if (strcmp(std::get<const char*>(scene.second), sceneName) == 0) {
            return true;
        }
    }
    return false;
}