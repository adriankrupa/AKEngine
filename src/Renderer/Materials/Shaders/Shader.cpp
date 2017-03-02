//
// Created by akrupa on 2017-02-24.
//

#include <glbinding/gl/gl.h>
#include <fstream>
#include <spdlog/spdlog.h>

#include "akengine/Renderer/Materials/Shaders/Shader.h"
#include "akengine/Utilities/GLDebug.h"

using namespace gl;
using namespace std;

Shader::~Shader() {
    if (program) {
        glUseProgram(0);
        glDeleteProgram(program);
        program = 0;
    }
}

bool Shader::isCompiled() {
    return compiled;
}

GLuint Shader::getProgram() {
    return program;
}

bool Shader::compileShaderFromPath(gl::GLuint* shader, gl::GLenum type, std::string filePath) {

    ifstream fileStream;
    fileStream.open(filePath, ios_base::in);

    string contents((istreambuf_iterator<char>(fileStream)),
                    istreambuf_iterator<char>());

    fileStream.close();

    if (contents.length() <= 0) {
        auto console = spdlog::get("console");
        console->error("Failed to load shader: " + filePath);
        compiled = false;
        return false;
    }

    return compileShader(shader, type, contents);
}

bool Shader::compileShader(gl::GLuint* shader, gl::GLenum type, std::string shaderString) {
    GLint status;
    auto sources = shaderString.c_str();

    if (sources == NULL || strlen(sources) <= 0) {
        auto console = spdlog::get("console");
        console->error("Failed to load shader: " + shaderString);
        compiled = false;
        return false;
    }
    auto sh = shaderString;
    const GLchar *source = sh.c_str();

    auto shaderInt = glCreateShader(type);
    *shader = shaderInt;
    GL_CHECK(glShaderSource(*shader, 1, &source, NULL));
    GL_CHECK(glCompileShader(*shader));


#ifndef NDEBUG
        GLint logLength = 0;
        GL_CHECK(glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLength));
        if (logLength > 1) {
            GLchar *log = (GLchar *) malloc((size_t)logLength);
            GL_CHECK(glGetShaderInfoLog(*shader, logLength, &logLength, log));
            auto console = spdlog::get("console");
            console->error("Shader compile log: " + std::string(log));
            free(log);
        }
#endif

    GL_CHECK(glGetShaderiv(*shader, GL_COMPILE_STATUS, &status));
    if (status == 0) {
        glDeleteShader(*shader);
        compiled = false;
        return false;
    }
    return true;
}

bool Shader::linkProgram(GLuint prog) {
    GLint status;
    glLinkProgram(prog);

#if defined(_DEBUG) && !defined(_TEST)
    GLint logLength;
        GL_CHECK(glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLength));
        if (logLength > 1) {
            GLchar *log = (GLchar *) malloc(logLength);
            GL_CHECK(glGetProgramInfoLog(prog, logLength, &logLength, log));
            LOG(ERROR) << "Program " << getShaderName() << " link log: " << endl << log;
            free(log);
        }
#endif

    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    return status != 0;
}

bool Shader::attachShaders(GLuint shader1, GLuint shader2) {

    GLuint vertShader = shader1;
    GLuint fragShader = shader2;

    GL_CHECK(glAttachShader(program, vertShader));
    GL_CHECK(glAttachShader(program, fragShader));

//    bindAttributeLocations();
//
    if (!linkProgram(program)) {
        auto console = spdlog::get("console");
        console->error("Failed to link program: "/* + getShaderName()*/);

        if (vertShader) {
            GL_CHECK(glDeleteShader(vertShader));
            vertShader = 0;
        }
        if (fragShader) {
            GL_CHECK(glDeleteShader(fragShader));
            fragShader = 0;
        }
        if (program) {
            GL_CHECK(glDeleteProgram(program));
            program = 0;
        }
        return false;
    }
//
//    fetchUniformLocations();

    if (vertShader) {
        GL_CHECK(glDetachShader(program, vertShader));
        GL_CHECK(glDeleteShader(vertShader));
    }

    if (fragShader) {
        GL_CHECK(glDetachShader(program, fragShader));
        GL_CHECK(glDeleteShader(fragShader));
    }
    return true;
}

void Shader::fetchUniformLocations() {
    for (auto &uniform : uniforms) {
        GL_CHECK_RETURN(GLint pos = glGetUniformLocation(program, uniform.c_str()));
        if (pos < 0) {
            auto console = spdlog::get("console");
            console->warn("Couldn't fetch uniform location: " + uniform);
        } else {
            uniformsLocations.insert(pair<string, GLint>(uniform, pos));
        }
    }
    for (auto &uniform : uniformsBlocks) {
        GL_CHECK_RETURN(GLint pos = glGetUniformBlockIndex(program, uniform.c_str()));
        if (pos < 0) {
            auto console = spdlog::get("console");
            console->warn("Couldn't fetch uniform location: " + uniform);
        } else {
            uniformsLocations.insert(pair<string, GLint>(uniform, pos));
        }
    }
}
