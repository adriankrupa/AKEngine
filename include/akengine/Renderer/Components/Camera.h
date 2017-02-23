//
// Created by Adrian Krupa on 22.02.2017.
//

#ifndef AKENGINE_CAMERA_H
#define AKENGINE_CAMERA_H

#include <glm/glm.hpp>

#include "Component.h"

enum class CameraClearFlag {
    DontClear,
    SolidColor,
    Skybox,
    OnlyDepth
};

class Camera : public Component {

    CameraClearFlag clearFlag = CameraClearFlag::SolidColor;
    glm::vec4 clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    glm::vec4 viewport = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

public:
    Camera();

    void Clear() const;

    virtual std::string GetName() const override ;


};


#endif //AKENGINE_CAMERA_H
