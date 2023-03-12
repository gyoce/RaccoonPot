cmake_minimum_required(VERSION 3.14)

add_subdirectory(DemoGame)
add_subdirectory(ECSGameEngine)

include_directories(DemoGame/src)
include_directories(ECSGameEngine/src)

add_executable(DemoGame Main.cpp)
target_link_libraries(DemoGame PRIVATE demogame ecsgameengine)