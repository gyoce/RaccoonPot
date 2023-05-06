cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/inc
    ${CMAKE_ROOT_DIR}/tests/Common
)

add_executable(${TEST_EXEC_NAME}
    Main.cpp

    UnitTests/ComponentArrayTest.cpp
    UnitTests/ComponentManagerTest.cpp
    UnitTests/EntityManagerTest.cpp
    UnitTests/EventManagerTest.cpp
    UnitTests/GuiManagerTest.cpp
    UnitTests/GuiWidgetTest.cpp
    UnitTests/LogTest.cpp
    UnitTests/ResourceManagerTest.cpp
    UnitTests/SceneManagerTest.cpp
    UnitTests/SpriteSheetTest.cpp
    UnitTests/SystemManagerTest.cpp

    IntegrationTests/CoordinatorTest.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${TEST_EXEC_NAME} ${RACCOON_POT_LIBRARY} GTest::gtest)
include(GoogleTest)
gtest_discover_tests(${TEST_EXEC_NAME})