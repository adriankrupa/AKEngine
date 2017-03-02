//
// Created by Adrian Krupa on 28.02.2017.
//

#ifndef AKENGINE_UNLITSHADERTEST_H
#define AKENGINE_UNLITSHADERTEST_H

#include <gtest/gtest.h>
#include <akengine/Renderer/Materials/Shaders/Unlit/UnlitShader.h>

class AKEngine;

class UnlitShaderTest : public ::testing::Test {

protected:
    std::shared_ptr<AKEngine> engine;
    std::shared_ptr<UnlitShader> shader;

    virtual void SetUp();

    virtual void TearDown();
};


#endif //AKENGINE_UNLITSHADERTEST_H
