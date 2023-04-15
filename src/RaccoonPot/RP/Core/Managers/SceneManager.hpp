#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "../Scene.hpp"

#include <unordered_map>
#include <vector>

namespace RP {

    class SceneManager {
    public:
        SceneManager(int baseAction);

        template<class T> std::shared_ptr<T> RegisterScene(int action);

        int Loop();
    
    private:
        int baseAction;
        std::unordered_map<int, std::shared_ptr<Scene>> scenes{};
        std::vector<const char*> sceneNames{};
    };

}

#include "SceneManager.inl"

#endif // SCENE_MANAGER_HPP