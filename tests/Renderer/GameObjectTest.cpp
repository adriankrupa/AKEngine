//
// Created by akrupa on 2017-02-23.
//

#include "GameObjectTest.h"

TEST_F(GameObjectTest, TestDefaultTransform) {
    auto transform = gameObject->GetTransform();
    ASSERT_NE(nullptr, transform);
    ASSERT_EQ(3, transform.use_count());
}

void GameObjectTest::SetUp() {
    gameObject = GameObject::CreateGameObject();
}

void GameObjectTest::TearDown() {}
