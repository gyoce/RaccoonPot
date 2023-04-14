#include "Scene.hpp"

using namespace EcsGameEngine;

Scene::Scene(std::unique_ptr<Coordinator> coordinator) 
    : coordinator(std::move(coordinator)) {  }
