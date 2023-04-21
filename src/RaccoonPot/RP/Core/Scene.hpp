#ifndef RP_SCENE_HPP
#define RP_SCENE_HPP

namespace RP {

    class Scene {
    public:
        virtual ~Scene() = default;
        virtual int Loop() = 0;
    };

}

#endif // RP_SCENE_HPP