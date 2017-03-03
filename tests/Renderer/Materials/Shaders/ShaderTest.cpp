//
// Created by Adrian Krupa on 24.02.2017.
//

#include <akengine/AKEngine.h>
#include <glbinding/gl/gl.h>

#include "ShaderTest.h"

using namespace std;
using namespace gl;

std::string simpleVertexShader =
"#version 410 \n\
void main(void)\n\
{\n\
    gl_Position = vec4(0, 0, 0, 1);\n\
}";

std::string simpleFragmentShader =
"#version 410 \n\
out vec4 fragColor;\n\
void main(void)\n\
{\n\
    fragColor = vec4(0, 1, 0, 1);\n\
}";

TEST_F(ShaderTest, TestSimpleVertexShaderCompilation) {
    GLuint shaderObject;
    auto compilation = shader->compileShaderT(&shaderObject, GL_VERTEX_SHADER, simpleVertexShader);
    EXPECT_TRUE(compilation);
    EXPECT_LT(0, shaderObject);
}

TEST_F(ShaderTest, TestSimpleFragmentShaderCompilation) {
    GLuint shaderObject;
    auto compilation = shader->compileShaderT(&shaderObject, GL_FRAGMENT_SHADER, simpleFragmentShader);
    EXPECT_TRUE(compilation);
    EXPECT_LT(0, shaderObject);
}

TEST_F(ShaderTest, TestSimpleVertexShaderLinking) {
    GLuint vertexShaderObject;
    auto vertexCompilation = shader->compileShaderT(&vertexShaderObject, GL_VERTEX_SHADER, simpleVertexShader);
    EXPECT_TRUE(vertexCompilation);
    EXPECT_LT(0, vertexShaderObject);

    GLuint fragmentShaderObject;
    auto fragmentCompilation = shader->compileShaderT(&fragmentShaderObject, GL_FRAGMENT_SHADER, simpleFragmentShader);
    EXPECT_TRUE(fragmentShaderObject);
    EXPECT_LT(0, fragmentCompilation);

    auto linked = shader->attachShadersT(vertexShaderObject, fragmentShaderObject);
    EXPECT_TRUE(linked);
}

void ShaderMock::setup() {
    program = glCreateProgram();
}

bool ShaderMock::isUsingLight() {
    return false;
}

bool ShaderMock::compileShaderT(gl::GLuint *shader, gl::GLenum type, std::string shaderString) {
    return this->compileShader(shader, type, shaderString);
}

bool ShaderMock::attachShadersT(GLuint shader1, GLuint shader2) {
    return this->attachShaders(shader1, shader2);
}

void ShaderMock::bindAttributeLocations() {

}

void ShaderTest::SetUp() {
    engine = make_shared<AKEngine>();
    engine->init();
    engine->createHeadlessWindow();

    shader = make_shared<ShaderMock>();
    shader->setup();
}

void ShaderTest::TearDown() {
    engine->destroyWindow();
}


