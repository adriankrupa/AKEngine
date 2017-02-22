//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_TRANSFORMTEST_H
#define AKENGINE_TRANSFORMTEST_H

#include <gtest/gtest.h>
#include <akengine/Renderer/Components/Transform.h>


// The fixture for testing class Foo.
class TransformTest : public ::testing::Test {

protected:
    Transform* transform;

    virtual void SetUp();
    virtual void TearDown();
};


#endif //AKENGINE_TRANSFORMTEST_H
