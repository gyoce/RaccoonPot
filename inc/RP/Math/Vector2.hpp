#ifndef RP_VECTOR2_HPP
#define RP_VECTOR2_HPP

namespace RP {

    class Vector2 {
    public:
        Vector2() = default;
        Vector2(float x, float y);

        float x, y;
    };

} // namespace RP

#endif // RP_VECTOR2_HPP