#include <gtest/gtest.h>

#include <Core/Managers/EntityManager.hpp>

using namespace ECSGameEngine;

TEST(EntityManager, CreateEntity) {
    EntityManager em{};
    Entity entity1 = em.CreateEntity();
    EXPECT_EQ(entity1, 0);
    Entity entity2 = em.CreateEntity();
    EXPECT_EQ(entity2, 1);
}

TEST(EntityManager, GetSignature) {
    EntityManager em{};
    Signature signature{0b0101};
    Entity entity = em.CreateEntity();
    em.SetSignature(entity, signature);
    Signature signatureGet = em.GetSignature(entity);
    EXPECT_EQ(signature, signatureGet);
}

TEST(EntityManager, DestroyEntity) {
    EntityManager em{};
    Signature signature{0b1100};
    Entity entity = em.CreateEntity();
    em.SetSignature(entity, signature);
    em.DestroyEntity(entity);
    Signature signatureGet = em.GetSignature(entity);
    EXPECT_NE(signature, signatureGet);
}

TEST(EntityManagerDeath, TooManyEntities) {
    EntityManager em{};
    for (int i = 0; i < MAX_ENTITIES; i++) {
        em.CreateEntity();
    }
    ASSERT_DEATH({
        em.CreateEntity();
    }, "");
}

TEST(EntityManagerDeath, EntityOutOfRange) {
    EntityManager em{};
    Entity entity = MAX_ENTITIES + 1;
    ASSERT_DEATH({
        em.DestroyEntity(entity);
    }, "");
    ASSERT_DEATH({
        em.GetSignature(entity);
    }, "");
    ASSERT_DEATH({
        em.SetSignature(entity, Signature{});
    }, "");
}