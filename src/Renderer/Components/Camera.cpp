//
// Created by Adrian Krupa on 22.02.2017.
//

#include <glbinding/gl/gl.h>

#include "akengine/Renderer/Components/Camera.h"

using namespace gl;

Camera::Camera() {

}

void Camera::Clear() const {
    switch (clearFlag) {
        case CameraClearFlag::DontClear:
            break;
        case CameraClearFlag::SolidColor: {
            glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
            glDepthMask(GL_TRUE);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            break;
        }
        case CameraClearFlag::Skybox:break;
        case CameraClearFlag::OnlyDepth:break;
    }
}

std::string Camera::GetName() const {
    return "Camera";
}
