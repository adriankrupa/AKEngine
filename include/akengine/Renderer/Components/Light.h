//
// Created by akrupa on 2017-02-23.
//

#ifndef AKENGINE_LIGHT_H
#define AKENGINE_LIGHT_H

#include <glm/glm.hpp>

#include "Component.h"

enum class LightType : int {
    Directional,
    Point,
    Spot
};

struct LightStruct {
    LightType type;
    glm::vec3 direction;
    glm::vec3 position;
    float range;
    float spotAngle;
    float intensity;
    glm::vec3 color;
};

class Light : public Component {

public:
    static std::shared_ptr<Light> createLight();

    //region Getters
    LightType getLightType() const;

    glm::vec3 getLightDirection() const;

    glm::vec3 getLightPosition() const;

    float getLightRange() const;

    float getLightSpotAngle() const;

    float getLightIntensity() const;

    glm::vec3 getLightColor() const;

    LightStruct getLightStruct() const;
    //endregion

    //region Setters
    void setLightType(LightType lightType);

    void setLightRange(float lightRange);

    void setLightSpotAngle(float lightSpotAngle);

    void setLightIntensity(float lightIntensity);

    void setLightColor(glm::vec3 lightColor);
    //endregion

    virtual std::string GetName() const override final;


private:
    mutable LightStruct light;

    Light();

    void UpdateLightDirection() const;

    void UpdateLightPosition() const;
};


#endif //AKENGINE_LIGHT_H
