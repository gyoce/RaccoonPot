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

target_sources(${RACCOON_POT_LIBRARY} PRIVATE
    RP/Core/Managers/ComponentManager.cpp RP/Core/Managers/SystemManager.cpp RP/Core/Managers/EntityManager.cpp 
        RP/Core/Managers/SceneManager.cpp RP/Core/Managers/GuiManager.cpp
    RP/Core/Coordinator.cpp     
    RP/Math/Vector2.cpp
    RP/Logs/Log.cpp
)