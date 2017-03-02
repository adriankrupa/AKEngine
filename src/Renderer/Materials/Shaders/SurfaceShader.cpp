//
// Created by akrupa on 2017-02-24.
//

#include <glbinding/gl/gl.h>
#include <spdlog/spdlog.h>
#include <akengine/Utilities/WorkingDirectory.h>

#include "akengine/Renderer/Materials/Shaders/SurfaceShader.h"

using namespace gl;
using namespace std;

void SurfaceShader::setup() {
    GLuint vertShader, fragShader;
    string vertShaderPathname, fragShaderPathname;

    program = glCreateProgram();

    string shadersDirectory = "/shaders/";


    vertShaderPathname = WorkingDirectory::GetExecutableDirectory()
                         + shadersDirectory + getShaderName() + ".vsh";
//    vertShaderPathname = getShaderName() + ".vsh";
    vertShaderPathname = "../resources/shaders/unlit/" + getShaderName() + ".vsh";

    if (!compileShaderFromPath(&vertShader, GL_VERTEX_SHADER, vertShaderPathname)) {
#ifndef NDEBUG
        auto console = spdlog::get("console");
        console->error("Failed to compile vertex shader: " + getShaderName());
#endif
        return;
    }

    fragShaderPathname = WorkingDirectory::GetExecutableDirectory()
                         + shadersDirectory + getShaderName() + ".fsh";
    fragShaderPathname = "../resources/shaders/unlit/" + getShaderName() + ".fsh";

    if (!compileShaderFromPath(&fragShader, GL_FRAGMENT_SHADER, fragShaderPathname)) {
#ifndef NDEBUG
        auto console = spdlog::get("console");
        console->error("Failed to compile fragment shader: " + getShaderName());
#endif
        return;
    }
    attachShaders(vertShader, fragShader);
}


void SurfaceShader::setup(std::string vertexShaderString, std::string fragmentShaderString) {
    GLuint vertShader, fragShader;
    glCreateProgram();
    program = glCreateProgram();
    if (!compileShader(&vertShader, GL_VERTEX_SHADER, vertexShaderString)) {
#ifndef NDEBUG
        auto console = spdlog::get("console");
        console->error("Failed to compile vertex shader: " + getShaderName());
#endif
        return;
    }
    if (!compileShader(&fragShader, GL_FRAGMENT_SHADER, fragmentShaderString)) {
#ifndef NDEBUG
        auto console = spdlog::get("console");
        console->error("Failed to compile fragment shader: " + getShaderName());
#endif
        return;
    }
    attachShaders(vertShader, fragShader);
}
