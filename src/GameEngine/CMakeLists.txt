cmake_minimum_required(VERSION 3.8)

include_directories(src)

add_library(GameEngine
    src/Core/Managers/ComponentManager.cpp src/Core/Managers/SystemManager.cpp src/Core/Managers/EntityManager.cpp
    src/Core/Systems/System.cpp
    src/Core/Coordinator.cpp
)