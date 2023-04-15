#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace RP {

    class Vector2 {
    public:
        Vector2() = default;
        Vector2(float x, float y);

        float x, y;
    };

}

#endif // VECTOR2_HPP