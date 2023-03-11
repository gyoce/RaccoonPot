#include <gtest/gtest.h>

#include <Core/Managers/EntityManager.hpp>

using namespace GameEngine;

TEST(EntityManager, GetSignature) {
    EntityManager em{};
    Signature signature{0b0101};
    Entity entity = em.CreateEntity();
    em.SetSignature(entity, signature);
}