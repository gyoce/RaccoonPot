#include "Button.hpp"

#include <RP/Core/Components/Transform2.hpp>

RP::Entity Button::CreateButton(const std::unique_ptr<RP::Coordinator>& coordinator) {
    const RP::Entity button = coordinator->CreateEntity();
    coordinator->AddComponent(button, RP::Transform2{});
    return button;
}
