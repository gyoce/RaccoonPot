cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/external/SDL/include
    ${CMAKE_ROOT_DIR}/src/DemoGame/src
    ${CMAKE_ROOT_DIR}/src/ECSGameEngine/src
)

add_executable(${DEMO_GAME_EXEC_NAME} 
    Main.cpp
    src/Game.cpp
)

target_link_libraries(${DEMO_GAME_EXEC_NAME} PRIVATE ${ECS_GAME_ENGINE_LIBRARY} SDL3::SDL3)