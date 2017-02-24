//
// Created by akrupa on 2017-02-24.
//

#include <glbinding/gl/gl.h>

#include "akengine/Renderer/Materials/Shaders/SurfaceShader.h"

using namespace gl;
using namespace std;

void SurfaceShader::setup() {
    GLuint vertShader, fragShader;
    string vertShaderPathname, fragShaderPathname;

    program = glCreateProgram();

    string shadersDirectory = "/shaders/";

    vertShaderPathname = getShaderName() + ".vsh";

    if (!compileShader(&vertShader, GL_VERTEX_SHADER, vertShaderPathname)) {
//#if !defined(_TEST)
//        LOG(ERROR) << "Failed to compile vertex shader: " + getShaderName();
//#endif
        return;
    }

    fragShaderPathname = WorkingDirectory::GetExecutableDirectory()
                         + shadersDirectory + getShaderName() + ".fsh";
    if (!compileShader(&fragShader, GL_FRAGMENT_SHADER, fragShaderPathname)) {
//#if !defined(_TEST)
//        LOG(ERROR) << "Failed to compile fragment shader: " + getShaderName();
//#endif
        return;
    }
    attachShaders(vertShader, fragShader);
}

void SurfaceShader::setup(std::string vertexShaderString, std::string fragmentShaderString) {

}
