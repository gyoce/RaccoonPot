#include "Scene.hpp"

using namespace ECSGameEngine;

Scene::Scene(std::unique_ptr<Coordinator> coordinator) 
    : coordinator(std::move(coordinator)) {  }
