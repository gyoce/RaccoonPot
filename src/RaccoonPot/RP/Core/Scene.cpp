#include "Scene.hpp"

using namespace RP;

Scene::Scene(std::unique_ptr<Coordinator> coordinator) 
    : coordinator(std::move(coordinator)) {  }
