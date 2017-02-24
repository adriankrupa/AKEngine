//
// Created by akrupa on 2017-02-24.
//

#ifndef AKENGINE_SHADER_H
#define AKENGINE_SHADER_H

#include <glbinding/gl/types.h>
#include <memory>

class Shader {

public:
    virtual ~Shader();
    virtual void setup() = 0;
    virtual bool isUsingLight() = 0;
    bool isCompiled();
    gl::GLuint getProgram();

protected:
    gl::GLuint program;
    bool compiled = false;

    bool compileShader(gl::GLuint* shader, gl::GLenum type, std::string filePath);
    bool compileShader(gl::GLuint* shader, gl::GLenum type, std::string shaderString, std::string filePath);
    bool linkProgram(gl::GLuint prog);
    void attachShaders(gl::GLuint shader1, gl::GLuint shader2);

//    std::string generateShader(const std::string shader, const gl::GLenum type) const;
};


#endif //AKENGINE_SHADER_H
