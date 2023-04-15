#ifndef GRAPHIC_SYSTEM_HPP
#define GRAPHIC_SYSTEM_HPP

#include <memory>
#include <SDL2/SDL.h>
#include <RP/Core/Coordinator.hpp>
#include <RP/Core/Systems/System.hpp>

class RenderSystem : public RP::System {
public:
    void Update(float dt, const std::unique_ptr<RP::Coordinator>& coordinator, SDL_Renderer* renderer);

    static RP::Signature GetSignature(const std::unique_ptr<RP::Coordinator>& coordinator);
};

#endif // GRAPHIC_SYSTEM_HPP