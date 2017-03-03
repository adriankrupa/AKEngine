//
// Created by Adrian Krupa on 24.02.2017.
//

#ifndef AKENGINE_SHADERTEST_H
#define AKENGINE_SHADERTEST_H

#include <gtest/gtest.h>
#include <akengine/Renderer/Materials/Shaders/Shader.h>

class AKEngine;

class ShaderMock : public Shader {

public:
    virtual void setup() override;

    virtual bool isUsingLight() override;

    bool compileShaderT(gl::GLuint *shader, gl::GLenum type, std::string shaderString);

    bool attachShadersT(gl::GLuint shader1, gl::GLuint shader2);

protected:
    void bindAttributeLocations() override;
};

class ShaderTest : public ::testing::Test {

protected:
    std::shared_ptr<ShaderMock> shader;
    std::shared_ptr<AKEngine> engine;

    virtual void SetUp();

    virtual void TearDown();
};


#endif //AKENGINE_SHADERTEST_H
