cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/src/DemoGame/src
    ${CMAKE_ROOT_DIR}/inc
)

add_executable(${DEMO_GAME_EXEC_NAME} 
    Main.cpp
)

target_link_libraries(${DEMO_GAME_EXEC_NAME} PRIVATE ${RACCOON_POT_LIBRARY})