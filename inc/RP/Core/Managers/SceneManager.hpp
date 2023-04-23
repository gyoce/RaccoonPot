#ifndef RP_SCENE_MANAGER_HPP
#define RP_SCENE_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <memory>

#include <RP/Types.hpp>

namespace RP {

    class SceneManager {
    public:
        explicit SceneManager(int baseAction);
        template<class T, typename ...Args> std::shared_ptr<T> RegisterScene(int action, Args&&... args);
        int Loop();
    
    private:
        int baseAction;
        std::unordered_map<int, ScenePtr> scenes{};
        std::vector<const char*> sceneNames{};
    };

}

#include <RP/Core/Managers/SceneManager.inl>

#endif // RP_SCENE_MANAGER_HPP