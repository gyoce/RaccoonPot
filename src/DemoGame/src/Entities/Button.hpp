#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <RP/Core/Coordinator.hpp>

class Button {
public:
    static RP::Entity CreateButton(const std::unique_ptr<RP::Coordinator>& coordinator);
};

#endif // BUTTON_HPP