//
// Created by Adrian Krupa on 28.02.2017.
//

#ifndef AKENGINE_SURFACESHADERTEST_H
#define AKENGINE_SURFACESHADERTEST_H

#include <gtest/gtest.h>
#include <akengine/Renderer/Materials/Shaders/SurfaceShader.h>

class AKEngine;

class SurfaceShaderMock : public SurfaceShader {

    virtual std::string getShaderName() const override;

    virtual void bindAttributeLocations() override;

public:
    virtual void setup() override;

    virtual bool isUsingLight() override;
};

class SurfaceShaderTest : public ::testing::Test {

protected:
    std::shared_ptr<SurfaceShaderMock> shader;
    std::shared_ptr<AKEngine> engine;

    virtual void SetUp();

    virtual void TearDown();
};


#endif //AKENGINE_SURFACESHADERTEST_H
