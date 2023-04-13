#ifndef SCENE_HPP
#define SCENE_HPP

#include <Core/Coordinator.hpp>

namespace ECSGameEngine {

    class Scene {
    public:
        Scene(std::unique_ptr<Coordinator> coordinator);
        virtual int Loop() = 0;

    protected:
        std::unique_ptr<Coordinator> coordinator;
    };

}

#endif // SCENE_HPP