#include "RenderSystem.hpp"

#include <RP/Core/Components/Transform2.hpp>

RP::Signature RenderSystem::GetSignature(const std::unique_ptr<RP::Coordinator>& coordinator) {
    RP::Signature signature{};
    signature.set(coordinator->GetComponentType<RP::Transform2>());
    return signature;
}

void RenderSystem::Update(float dt, const std::unique_ptr<RP::Coordinator>& coordinator, SDL_Renderer* renderer) {
    for (const RP::Entity& entity : Entities) {
        const auto& transform = coordinator->GetComponent<RP::Transform2>(entity);
        SDL_SetRenderDrawColor(renderer, 128, 0, 0, 0);
        SDL_Rect rect = { static_cast<int>(transform.Position.x), static_cast<int>(transform.Position.y), 32, 32 };
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    }
}

