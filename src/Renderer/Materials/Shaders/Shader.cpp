//
// Created by akrupa on 2017-02-24.
//

#include <glbinding/gl/gl.h>
#include <fstream>
#include <cstring>

#include "akengine/Renderer/Materials/Shaders/Shader.h"

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

bool Shader::compileShader(gl::GLuint* shader, gl::GLenum type, std::string filePath) {

    ifstream fileStream;
    fileStream.open(filePath, ios_base::in);

    string contents((istreambuf_iterator<char>(fileStream)),
                    istreambuf_iterator<char>());

    fileStream.close();

    return compileShader(shader, type, contents, filePath);


}

bool Shader::compileShader(gl::GLuint* shader, gl::GLenum type, std::string shaderString, std::string filePath) {
    GLint status;
    auto sources = shaderString.c_str();

    if (sources == NULL || strlen(sources) <= 0) {
//        LOG(ERROR) << "Failed to load shader: " + filePath;
        compiled = false;
        return false;
    }
//    string sh = generateShader(shaderString, type);
    auto sh = shaderString;
    const GLchar *source = sh.c_str();

    auto shaderInt = glCreateShader(type);
    *shader = shaderInt;
    glShaderSource(*shader, 1, &source, NULL);
    glCompileShader(*shader);

#if defined(_DEBUG)
    GLint logLength;
        GL_CHECK(glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLength));
        if (logLength > 1) {
            GLchar *log = (GLchar *) malloc(logLength);
            GL_CHECK(glGetShaderInfoLog(*shader, logLength, &logLength, log));
            LOG(ERROR) << "Shader compile log: " << endl << log;
            free(log);
        }
#endif

    glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
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

void Shader::attachShaders(GLuint shader1, GLuint shader2) {

    GLuint vertShader = shader1;
    GLuint fragShader = shader2;

    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);

//    bindAttributeLocations();
//
//    if (!linkProgram(m_program)) {
//        LOG(ERROR) << "Failed to link program: " + getShaderName();
//
//        if (vertShader) {
//            GL_CHECK(glDeleteShader(vertShader));
//            vertShader = 0;
//        }
//        if (fragShader) {
//            GL_CHECK(glDeleteShader(fragShader));
//            fragShader = 0;
//        }
//        if (m_program) {
//            GL_CHECK(glDeleteProgram(m_program));
//            m_program = 0;
//        }
//    }
//
//    fetchUniformLocations();

    if (vertShader) {
        glDetachShader(program, vertShader);
        glDeleteShader(vertShader);
    }

    if (fragShader) {
        glDetachShader(program, fragShader);
        glDeleteShader(fragShader);
    }
}

//string Shader::generateShader(const string shader, const GLenum type) const {
//    auto s = shader;
//    auto verBegin = shader.find("#version");
//    auto verEnd = shader.find("\n", verBegin);
//    s.erase(verBegin, verEnd + 1);
//    s.insert(s.begin(), "#version 410\n");
//    return s;
//}