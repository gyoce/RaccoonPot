#ifndef SCENE_HPP
#define SCENE_HPP

namespace RP {

    class Scene {
    public:
        virtual ~Scene() = default;
        virtual int Loop() = 0;
    };

}

#endif // SCENE_HPP