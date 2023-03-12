cmake_minimum_required(VERSION 3.14)

include_directories(
    ../external/googletest/googletest/include
    ../external/googletest/googlemock/include
    ../src/ECSGameEngine/src
    Common
)

add_executable(${TEST_EXEC_NAME}
    UnitTests/ComponentArrayTest.cpp
    UnitTests/ComponentManagerTest.cpp
    UnitTests/SystemManagerTest.cpp
    UnitTests/EntityManagerTest.cpp

    IntegrationTests/CoordinatorTest.cpp
)

target_link_libraries(${TEST_EXEC_NAME} ecsgameengine gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(${TEST_EXEC_NAME})