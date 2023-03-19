cmake_minimum_required(VERSION 3.14)

include_directories(src)

add_library(ecsgameengine 
    src/Core/Managers/ComponentManager.cpp src/Core/Managers/SystemManager.cpp src/Core/Managers/EntityManager.cpp
    src/Core/Systems/System.cpp
    src/Core/Coordinator.cpp

    src/Logs/Log.cpp
)