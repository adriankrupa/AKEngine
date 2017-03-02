//
// Created by akrupa on 2017-02-24.
//

#ifndef AKENGINE_SHADER_H
#define AKENGINE_SHADER_H

#include <glbinding/gl/types.h>
#include <memory>
#include <map>
#include <vector>

class Shader {

public:
    virtual ~Shader();
    virtual void setup() = 0;
    virtual bool isUsingLight() = 0;
    bool isCompiled();
    gl::GLuint getProgram();

protected:
    gl::GLuint program;
    std::map<std::string, gl::GLint> uniformsLocations;
    std::vector<std::string> uniforms;
    std::vector<std::string> uniformsBlocks;
    bool compiled = false;

    bool compileShaderFromPath(gl::GLuint* shader, gl::GLenum type, std::string filePath);
    bool compileShader(gl::GLuint* shader, gl::GLenum type, std::string shaderString);
    bool linkProgram(gl::GLuint prog);
    bool attachShaders(gl::GLuint shader1, gl::GLuint shader2);

    virtual void bindAttributeLocations() = 0;
    virtual void fetchUniformLocations();
};


#endif //AKENGINE_SHADER_H
