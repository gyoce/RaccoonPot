cmake_minimum_required(VERSION 3.14)
project(RaccoonPot VERSION 1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}>)

set(TEST_EXEC_NAME ${PROJECT_NAME}Tests)
set(DEMO_GAME_EXEC_NAME ${PROJECT_NAME}Demo)
set(RACCOON_POT_LIBRARY ${PROJECT_NAME})
set(CMAKE_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(tests)
add_subdirectory(src)