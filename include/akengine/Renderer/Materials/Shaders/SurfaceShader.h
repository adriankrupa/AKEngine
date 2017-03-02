//
// Created by akrupa on 2017-02-24.
//

#ifndef AKENGINE_SURFACESHADER_H
#define AKENGINE_SURFACESHADER_H

#include "Shader.h"

class SurfaceShader : public Shader {

    virtual std::string getShaderName() const = 0;

public:
    virtual void setup() override;
    virtual void setup(std::string vertexShaderString, std::string fragmentShaderString);
};


#endif //AKENGINE_SURFACESHADER_H
