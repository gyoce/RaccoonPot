cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/src/RaccoonPot
    ${CMAKE_ROOT_DIR}/tests/Common
)

add_executable(${TEST_EXEC_NAME}
    UnitTests/ComponentArrayTest.cpp
    UnitTests/ComponentManagerTest.cpp
    UnitTests/EntityManagerTest.cpp
    UnitTests/EventManagerTest.cpp
    UnitTests/GuiManagerTest.cpp
    UnitTests/LogTest.cpp
    UnitTests/SceneManagerTest.cpp
    UnitTests/SystemManagerTest.cpp

    IntegrationTests/CoordinatorTest.cpp
)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${TEST_EXEC_NAME} ${RACCOON_POT_LIBRARY} GTest::gtest_main GTest::gtest)
include(GoogleTest)
gtest_discover_tests(${TEST_EXEC_NAME})