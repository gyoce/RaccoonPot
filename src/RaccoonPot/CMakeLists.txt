cmake_minimum_required(VERSION 3.14)

include_directories(
    RP
    ${CMAKE_ROOT_DIR}/inc
)

if(BUILD_SHARED_LIBS)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    add_library(${RACCOON_POT_LIBRARY} SHARED)
else()
    add_library(${RACCOON_POT_LIBRARY} STATIC)
endif()

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${RACCOON_POT_LIBRARY}
    PUBLIC
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(${RACCOON_POT_LIBRARY} 
    PUBLIC 
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)

target_sources(${RACCOON_POT_LIBRARY} PRIVATE
    RP/Game.cpp
    RP/Core/Managers/ComponentManager.cpp RP/Core/Managers/SystemManager.cpp RP/Core/Managers/EntityManager.cpp
        RP/Core/Managers/SceneManager.cpp RP/Core/Managers/GuiManager.cpp
    RP/Core/Coordinator.cpp RP/Core/Scene.cpp
    RP/Math/Vector2.cpp RP/Math/Vector3Int.cpp
    RP/Logs/Log.cpp
    RP/Gui/GuiWidget.cpp RP/Gui/GuiPanel.cpp RP/Gui/GuiButton.cpp
)