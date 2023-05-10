cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/inc
    ${CMAKE_ROOT_DIR}/tests/Common
)

add_executable(${TEST_EXEC_NAME}
    Main.cpp

    tests/ComponentArrayTest.cpp
    tests/ComponentManagerTest.cpp
    tests/CoordinatorTest.cpp
    tests/EntityManagerTest.cpp
    tests/EventManagerTest.cpp
    tests/GuiManagerTest.cpp
    tests/GuiWidgetTest.cpp
    tests/LogTest.cpp
    tests/ResourceManagerTest.cpp
    tests/SceneManagerTest.cpp
    tests/SpriteSheetTest.cpp
    tests/SystemManagerTest.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${TEST_EXEC_NAME} ${RACCOON_POT_LIBRARY} GTest::gtest)
include(GoogleTest)
gtest_discover_tests(${TEST_EXEC_NAME})