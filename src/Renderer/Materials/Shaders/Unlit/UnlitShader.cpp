//
// Created by Adrian Krupa on 24.02.2017.
//

#include <glbinding/gl/gl.h>

#include "akengine/Renderer/Materials/Shaders/Unlit/UnlitShader.h"
#include "../VertexAttrib.h"

using namespace std;
using namespace gl;

string UnlitShader::getShaderName() const {
    return "UnlitShader";
}

void UnlitShader::bindAttributeLocations() {
    glBindAttribLocation(program, VertexAttribPosition, "in_Position");
    glBindAttribLocation(program, VertexAttribColor, "in_Color");
}

void UnlitShader::fetchUniformLocations() {
    uniforms.push_back("MATRIX_MVP");
    SurfaceShader::fetchUniformLocations();
}

bool UnlitShader::isUsingLight() {
    return false;
}