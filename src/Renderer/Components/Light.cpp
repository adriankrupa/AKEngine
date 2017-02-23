//
// Created by akrupa on 2017-02-23.
//

#include "akengine/Renderer/Components/Light.h"
#include "akengine/Renderer/Components/Transform.h"

using namespace glm;

std::shared_ptr<Light> Light::createLight() {
    auto light = std::shared_ptr<Light>();
    light->Init();
    return light;
}

//region Getters
LightType Light::getLightType() const {
    return light.type;
}

vec3 Light::getLightDirection() const {
    UpdateLightDirection();
    return light.direction;
}

vec3 Light::getLightPosition() const {
    UpdateLightPosition();
    return light.position;
}

float Light::getLightRange() const {
    return light.range;
}

float Light::getLightSpotAngle() const {
    return light.spotAngle;
}

float Light::getLightIntensity() const {
    return light.intensity;
}

vec3 Light::getLightColor() const {
    return light.color;
}

LightStruct Light::getLightStruct() const {
    UpdateLightDirection();
    UpdateLightPosition();
    return light;
}
//endregion

//region Setters
void Light::setLightType(LightType lightType) {
    light.type = lightType;
}

void Light::setLightRange(float lightRange) {
    lightRange = glm::max(0.0f, lightRange);
    light.range = lightRange;
}

void Light::setLightSpotAngle(float lightSpotAngle) {
    lightSpotAngle = glm::clamp(lightSpotAngle, 0.0f, (float)M_PI);
    light.spotAngle = lightSpotAngle;
}

void Light::setLightIntensity(float lightIntensity) {
    lightIntensity = glm::max(0.0f, lightIntensity);
    light.intensity = lightIntensity;
}

void Light::setLightColor(vec3 lightColor) {
    lightColor = max(vec3(0,0,0), min(vec3(1,1,1), lightColor));
    light.color = lightColor;
}
//endregion

Light::Light() {

}

void Light::UpdateLightDirection() const {
    light.direction = vec3(1.0f, 0.0f, 0.0f) * GetTransform()->getRotation();
}

void Light::UpdateLightPosition() const {
    light.position = GetTransform()->getPosition();
}
