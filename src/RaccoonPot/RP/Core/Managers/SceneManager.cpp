#include "RP/Core/Managers/SceneManager.hpp"

#include "RP/Core/Scene.hpp"

using namespace RP;

SceneManager::SceneManager(SDL_Renderer* renderer)
    : renderer(renderer) {  }

int SceneManager::Loop() {
    assert(scenes.find(baseAction) != scenes.end() && "Scene with base action not present.");
    ScenePtr actualScene = scenes[baseAction];
    int loopRes = actualScene->Loop();
    while (scenes.find(loopRes) != scenes.end()) {
        actualScene = scenes[loopRes];
        loopRes = actualScene->Loop();
    }
    return loopRes;
}

void SceneManager::SetBaseAction(const int baseAction) {
    this->baseAction = baseAction;
}