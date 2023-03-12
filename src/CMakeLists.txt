cmake_minimum_required(VERSION 3.14)

add_subdirectory(DemoGame)
add_subdirectory(ECSGameEngine)

include_directories(DemoGame/src)
include_directories(ECSGameEngine/src)

add_executable(${DEMO_GAME_EXEC_NAME} Main.cpp)
target_link_libraries(${DEMO_GAME_EXEC_NAME} PRIVATE demogame ecsgameengine)