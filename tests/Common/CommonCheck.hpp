#ifndef TESTS_COMMON_CHECK_HPP
#define TESTS_COMMON_CHECK_HPP

#include <gtest/gtest.h>
#include <RP/RP.hpp>

inline void RP_EXPECT_EQ_POSITION(const RP::Vector3Int& vector, const int x, const int y, const int z) {
    EXPECT_EQ(vector.x, x);
    EXPECT_EQ(vector.y, y);
    EXPECT_EQ(vector.z, z);
}

inline void RP_EXPECT_EQ_SIZE(const int width, const int height, const int expectedWidth, const int expectedHeight) {
    EXPECT_EQ(width, expectedWidth);
    EXPECT_EQ(height, expectedHeight);
}

#endif // TESTS_COMMON_CHECK_HPP