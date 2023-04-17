cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/src/DemoGame/src
    ${CMAKE_ROOT_DIR}/src/RaccoonPot
)

add_executable(${DEMO_GAME_EXEC_NAME} 
    Main.cpp
    src/Game.cpp
    src/Scenes/MenuScene.cpp 
)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${DEMO_GAME_EXEC_NAME} 
    PRIVATE 
    ${RACCOON_POT_LIBRARY} 
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(${DEMO_GAME_EXEC_NAME} 
    PRIVATE 
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)