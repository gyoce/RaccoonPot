#ifndef SCENE_HPP
#define SCENE_HPP

#include "Coordinator.hpp"

namespace RP {

    class Scene {
    public:
        explicit Scene(std::unique_ptr<Coordinator> coordinator);
        virtual int Loop() = 0;

    protected:
        std::unique_ptr<Coordinator> coordinator;
    };

}

#define SCENE_CONSTRUCTOR(SceneName) explicit SceneName(std::unique_ptr<RP::Coordinator> coordinator) : Scene(std::move(coordinator)) {}

#endif // SCENE_HPP