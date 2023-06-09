#include <RP/Core/Managers/EntityManager.hpp>
#include <RP/Core/Managers/SystemManager.hpp>
#include <RP/Core/Managers/ComponentManager.hpp>

template<class T>
void RP::Coordinator::RegisterComponent() const {
    componentManager->RegisterComponent<T>();
}

template<class T>
void RP::Coordinator::AddComponent(const Entity entity, T component) {
    componentManager->AddComponent<T>(entity, component);
    Signature signature = entityManager->GetSignature(entity);
    signature.set(componentManager->GetComponentType<T>(), true);
    entityManager->SetSignature(entity, signature);
    systemManager->EntitySignatureChanged(entity, signature);
}

template<class T>
void RP::Coordinator::RemoveComponent(const Entity entity) const {
    componentManager->RemoveComponent<T>(entity);
    Signature signature = entityManager->GetSignature(entity);
    signature.set(componentManager->GetComponentType<T>(), false);
    entityManager->SetSignature(entity, signature);
    systemManager->EntitySignatureChanged(entity, signature);
}

template<class T>
T& RP::Coordinator::GetComponent(const Entity entity) {
    return componentManager->GetComponent<T>(entity);
}

template<class T>
RP::ComponentType RP::Coordinator::GetComponentType() const {
    return componentManager->GetComponentType<T>();
}

template<class T>
std::shared_ptr<T> RP::Coordinator::RegisterSystem() {
    return systemManager->RegisterSystem<T>();
}

template<class T>
void RP::Coordinator::SetSystemSignature(const Signature signature) const {
    systemManager->SetSignature<T>(signature);
}