//
// Created by Adrian Krupa on 24.02.2017.
//

#ifndef AKENGINE_UNLITSHADER_H
#define AKENGINE_UNLITSHADER_H


#include <akengine/Renderer/Materials/Shaders/SurfaceShader.h>

class UnlitShader: public SurfaceShader {

protected:
    virtual std::string getShaderName() const override final;
    virtual void bindAttributeLocations() override;
    virtual void fetchUniformLocations() override;
    virtual bool isUsingLight() override;
};


#endif //AKENGINE_UNLITSHADER_H
