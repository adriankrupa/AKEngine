//
// Created by akrupa on 2017-02-23.
//

#ifndef AKENGINE_GAMEOBJECTTEST_H
#define AKENGINE_GAMEOBJECTTEST_H

#include <gtest/gtest.h>
#include <akengine/Renderer/GameObject.h>

class GameObjectTest : public ::testing::Test {

protected:
    std::shared_ptr<GameObject> gameObject;

    virtual void SetUp();
    virtual void TearDown();
};


#endif //AKENGINE_GAMEOBJECTTEST_H
