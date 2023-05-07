#ifndef RP_VECTOR3_INT_HPP
#define RP_VECTOR3_INT_HPP

namespace RP {

    class Vector3Int {
    public:
        Vector3Int() = default;
        Vector3Int(int x, int y, int z);

        int x, y, z;
    };

} // namespace RP

#endif // RP_VECTOR3_HPP