#include "SceneManager.hpp"

using namespace ECSGameEngine;

SceneManager::SceneManager(int action) 
	: baseAction(action) {  }

int SceneManager::Loop() {
	assert(scenes.find(baseAction) != scenes.end() && "Scene with base action not present.");
	std::shared_ptr<Scene> actualScene = scenes[baseAction];
	int loopRes = actualScene->Loop();
	while (scenes.find(loopRes) != scenes.end()) {
		actualScene = scenes[loopRes];
		loopRes = actualScene->Loop();
	}
	return loopRes;
}