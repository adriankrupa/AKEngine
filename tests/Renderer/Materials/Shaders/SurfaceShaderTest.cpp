//
// Created by Adrian Krupa on 28.02.2017.
//

#include <akengine/AKEngine.h>
#include <glbinding/gl/gl.h>

#include "SurfaceShaderTest.h"

using namespace std;
using namespace gl;

string SurfaceShaderMock::getShaderName() const {
    return std::string();
}

void SurfaceShaderMock::bindAttributeLocations() {

}

void SurfaceShaderMock::setup() {
    SurfaceShader::setup();
}

bool SurfaceShaderMock::isUsingLight() {
    return false;
}

void SurfaceShaderTest::SetUp() {
}

void SurfaceShaderTest::TearDown() {
    engine = make_shared<AKEngine>();
    engine->init();
    engine->createHeadlessWindow();

    shader = make_shared<SurfaceShaderMock>();
    shader->setup();
}
