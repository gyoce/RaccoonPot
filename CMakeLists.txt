cmake_minimum_required(VERSION 3.14)
project(ECSGameEngine VERSION 1.0)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(TEST_EXEC_NAME ${PROJECT_NAME}Tests)

add_subdirectory(external/googletest)
add_subdirectory(tests)
add_subdirectory(src)