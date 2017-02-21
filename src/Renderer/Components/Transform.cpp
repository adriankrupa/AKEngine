//
// Created by akrupa on 2017-02-21.
//

#include "akengine/Renderer/Components/Transform.h"


using namespace glm;

Transform::Transform() : Component() {
//    isUnique = true;
    this->position = vec3(0.0f, 0.0f, 0.0f);
    this->scale = vec3(1.0f, 1.0f, 1.0f);
    this->rotation = quat(1.0f, 0.0f, 0.0f, 0.0f);
    transformChanged = true;
    localFrameHash = 0;
    modelMatrixChanged = false;
}

vec3 Transform::getPosition() const {
    return position;
}

vec3 Transform::getScale() const {
    return scale;
}

quat Transform::getRotation() const {
    return rotation;
}

vec3 Transform::getRotationInEulerAngles() const {
    return rotationInEulerAngles;
}

mat4 Transform::getModelMatrix() const {
    recomputeMatrices();
    return cachedModelMatrix;
}

mat4 Transform::getNormalMatrix() const {
//    bool _transformChanged = transformChanged;
//    recomputeMatrices();
//    int hash = RendererManager::getInstance().getFrameHash();
//    if (_transformChanged || hash != localFrameHash) {
//        localFrameHash = hash;
//        Camera *currentCamera = RendererManager::getInstance().getCurrentCamera();
//        if (currentCamera != nullptr) {
//            mat4 cameraViewMatrix = currentCamera->getViewMatrix();
//            if (scale.x == scale.y && scale.y == scale.z) {
//                cachedNormalMatrix = cameraViewMatrix*cachedModelMatrix ;
//            } else {
//                cachedNormalMatrix = transpose(inverse(cameraViewMatrix*cachedModelMatrix));
//            }
//        }
//    }
    return cachedNormalMatrix;
}

mat4 Transform::getViewMatrix() const {
    recomputeMatrices();
    if (modelMatrixChanged) {
        modelMatrixChanged = false;
        cachedViewMatrix = inverse(getModelMatrix());
    }
    return cachedViewMatrix;
}

void Transform::setPosition(vec3 position) {
    this->position = position;
    transformChanged = true;
}

void Transform::setScale(vec3 scale) {
    this->scale = scale;
    transformChanged = true;
}

void Transform::setRotation(quat rotation) {
    this->rotation = normalize(rotation);
    this->rotationInEulerAngles = eulerAngles(rotation);
    transformChanged = true;
}

void Transform::setRotation(vec3 eulerAngles) {
    this->rotationInEulerAngles = eulerAngles;
    this->rotation = normalize(quat(eulerAngles));
    transformChanged = true;
}

std::string Transform::GetName() const {
    return "Transform";
}

void Transform::recomputeMatrices() const {
    if (transformChanged) {
        transformChanged = false;
//        cachedModelMatrix =  translate(mat4(), position) * mat4_cast(rotation) * glm::scale(mat4(), scale);
        modelMatrixChanged = true;
    }
}