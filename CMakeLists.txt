cmake_minimum_required(VERSION 3.14)
project(RaccoonPot VERSION 1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}>)
set(BUILD_SHARED_LIBS ON)

set(TEST_EXEC_NAME ${PROJECT_NAME}Tests)
set(DEMO_GAME_EXEC_NAME ${PROJECT_NAME}Demo)
set(RACCOON_POT_LIBRARY ${PROJECT_NAME})
set(CMAKE_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(tests)
add_subdirectory(src)

add_custom_target(copy_res COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_ROOT_DIR}/res ${CMAKE_BINARY_DIR}/res)
add_custom_target(copy_res_tests COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_ROOT_DIR}/res ${CMAKE_BINARY_DIR}/tests/res)
add_dependencies(${DEMO_GAME_EXEC_NAME} copy_res copy_res_tests)