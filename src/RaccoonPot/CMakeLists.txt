cmake_minimum_required(VERSION 3.14)

include_directories(RP)

add_library(${RACCOON_POT_LIBRARY})

target_sources(${RACCOON_POT_LIBRARY} PRIVATE
    RP/Core/Managers/ComponentManager.cpp RP/Core/Managers/SystemManager.cpp RP/Core/Managers/EntityManager.cpp 
        RP/Core/Managers/SceneManager.cpp RP/Core/Managers/GuiManager.cpp
    RP/Core/Systems/System.cpp
    RP/Core/Coordinator.cpp RP/Core/Scene.cpp    
    RP/Math/Vector2.cpp
    RP/Logs/Log.cpp
)