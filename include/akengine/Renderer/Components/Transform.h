//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_TRANSFORM_H
#define AKENGINE_TRANSFORM_H


#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Component.h"

class Transform final: public Component {

    glm::vec3 position;
    glm::vec3 scale;
    glm::quat rotation;
    glm::vec3 rotationInEulerAngles;

    mutable bool transformChanged;
    mutable bool modelMatrixChanged;
    mutable int localFrameHash;
    mutable glm::mat4 cachedModelMatrix;
    mutable glm::mat4 cachedNormalMatrix;
    mutable glm::mat4 cachedViewMatrix;

    void recomputeMatrices() const;

public:
    Transform();

    glm::vec3 getPosition() const;

    glm::vec3 getScale() const;

    glm::quat getRotation() const;

    glm::vec3 getRotationInEulerAngles() const;

    glm::mat4 getModelMatrix() const;

    glm::mat4 getNormalMatrix() const;

    glm::mat4 getViewMatrix() const;

    void setPosition(glm::vec3 position);

    void setScale(glm::vec3 scale);

    void setRotation(glm::quat rotation);

    void setRotation(glm::vec3 eulerAngles);

    virtual std::string GetName() const override final;

};


#endif //AKENGINE_TRANSFORM_H
