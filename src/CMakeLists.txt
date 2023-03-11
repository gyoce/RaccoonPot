cmake_minimum_required(VERSION 3.8)

add_subdirectory(Game)
add_subdirectory(GameEngine)

include_directories(Game/src)
include_directories(GameEngine/src)

add_executable(${PROJECT_NAME} Main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE game GameEngine)