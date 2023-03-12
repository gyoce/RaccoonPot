#include "Coordinator.hpp"

using namespace ECSGameEngine;

template<class T> 
void Coordinator::RegisterComponent() {
    componentManager->RegisterComponent<T>();
}

template<class T> 
void Coordinator::AddComponent(Entity entity, T component) {
    componentManager->AddComponent<T>(entity, component);
    Signature signature = entityManager->GetSignature(entity);
    signature.set(componentManager->GetComponentType<T>(), true);
    entityManager->SetSignature(entity, signature);
    systemManager->EntitySignatureChanged(entity, signature);
}

template<class T> 
void Coordinator::RemoveComponent(Entity entity) {
    componentManager->RemoveComponent<T>(entity);
    Signature signature = entityManager->GetSignature(entity);
    signature.set(componentManager->GetComponentType<T>(), false);
    entityManager->SetSignature(entity, signature);
    systemManager->EntitySignatureChanged(entity, signature);
}

template<class T> 
T& Coordinator::GetComponent(Entity entity) {
    return componentManager->GetComponent<T>(entity);
}

template<class T>
ComponentType Coordinator::GetComponentType() {
    return componentManager->GetComponentType<T>();
}

template<class T> 
std::shared_ptr<T> Coordinator::RegisterSystem() {
    return systemManager->RegisterSystem<T>();
}

template<class T> 
void Coordinator::SetSystemSignature(Signature signature) {
    systemManager->SetSignature<T>(signature);
}