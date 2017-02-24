//
// Created by akrupa on 2017-02-24.
//

#ifndef AKENGINE_LIGHTTEST_H
#define AKENGINE_LIGHTTEST_H

#include <gtest/gtest.h>
#include <akengine/Renderer/Components/Light.h>

class LightTest : public ::testing::Test  {

protected:
    std::shared_ptr<Light> light;
    std::shared_ptr<Light> lightWithGO;
    std::shared_ptr<GameObject> goWithLight;

    virtual void SetUp();
    virtual void TearDown();

};


#endif //AKENGINE_LIGHTTEST_H
