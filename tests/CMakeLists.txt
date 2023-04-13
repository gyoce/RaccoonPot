cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/src/ECSGameEngine/src
    ${CMAKE_ROOT_DIR}/tests/Common
)

add_executable(${TEST_EXEC_NAME}
    UnitTests/ComponentArrayTest.cpp
    UnitTests/ComponentManagerTest.cpp
    UnitTests/SystemManagerTest.cpp
    UnitTests/EntityManagerTest.cpp
    UnitTests/SceneManagerTest.cpp
    UnitTests/LogTest.cpp

    IntegrationTests/CoordinatorTest.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${TEST_EXEC_NAME} ${ECS_GAME_ENGINE_LIBRARY} GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(${TEST_EXEC_NAME})