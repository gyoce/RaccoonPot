#include <gtest/gtest.h>

#include <CommonTypes.hpp>

TEST(EntityManager, CreateEntity) {
    RP::EntityManager em{};
    const RP::Entity entity1 = em.CreateEntity();
    EXPECT_EQ(entity1, 0);
    const RP::Entity entity2 = em.CreateEntity();
    EXPECT_EQ(entity2, 1);
}

TEST(EntityManager, GetSignature) {
    RP::EntityManager em{};
    constexpr RP::Signature signature{ 0b0101 };
    const RP::Entity entity = em.CreateEntity();
    em.SetSignature(entity, signature);
    const RP::Signature signatureGet = em.GetSignature(entity);
    EXPECT_EQ(signature, signatureGet);
}

TEST(EntityManager, DestroyEntity) {
    RP::EntityManager em{};
    constexpr RP::Signature signature{ 0b1100 };
    const RP::Entity entity = em.CreateEntity();
    em.SetSignature(entity, signature);
    em.DestroyEntity(entity);
    const RP::Signature signatureGet = em.GetSignature(entity);
    EXPECT_NE(signature, signatureGet);
}

#ifndef NDEBUG

TEST(EntityManagerDeath, TooManyEntities) {
    RP::EntityManager em{};
    for (int i = 0; i < RP::MAX_ENTITIES; i++) {
        em.CreateEntity();
    }
    ASSERT_DEATH({
        em.CreateEntity();
    }, "");
}

TEST(EntityManagerDeath, EntityOutOfRange) {
    RP::EntityManager em{};
    constexpr RP::Entity entity = RP::MAX_ENTITIES + 1;
    ASSERT_DEATH({
        em.DestroyEntity(entity);
    }, "");
    ASSERT_DEATH({
        em.GetSignature(entity);
    }, "");
    ASSERT_DEATH({
        em.SetSignature(entity, RP::Signature{});
    }, "");
}

#endif // NDEBUG