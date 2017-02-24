//
// Created by akrupa on 2017-02-24.
//

#include <akengine/Renderer/GameObject.h>

#include "LightTest.h"

TEST_F(LightTest, TestDefaultLight) {
    ASSERT_NE(nullptr, light);
    ASSERT_NE(nullptr, lightWithGO);
}

TEST_F(LightTest, TestDefaultLightType) {
    ASSERT_EQ(LightType::Point, light->getLightType());
    ASSERT_EQ(LightType::Point, lightWithGO->getLightType());
}

TEST_F(LightTest, TestDefaultLightDirection) {
    auto dir = lightWithGO->getLightDirection();
    ASSERT_FLOAT_EQ(1, dir.x);
    ASSERT_FLOAT_EQ(0, dir.y);
    ASSERT_FLOAT_EQ(0, dir.z);
}

TEST_F(LightTest, TestDefaultLightPosition) {
    auto position = lightWithGO->getLightPosition();
    ASSERT_FLOAT_EQ(0, position.x);
    ASSERT_FLOAT_EQ(0, position.y);
    ASSERT_FLOAT_EQ(0, position.z);
}

TEST_F(LightTest, TestDefaultLightRange) {
    ASSERT_FLOAT_EQ(1, light->getLightRange());
    ASSERT_FLOAT_EQ(1, lightWithGO->getLightRange());
}

TEST_F(LightTest, TestDefaultLightSpotAngle) {
    ASSERT_FLOAT_EQ(M_PI_2, light->getLightSpotAngle());
    ASSERT_FLOAT_EQ(M_PI_2, lightWithGO->getLightSpotAngle());
}

TEST_F(LightTest, TestDefaultLightIntensity) {
    ASSERT_FLOAT_EQ(1, light->getLightIntensity());
    ASSERT_FLOAT_EQ(1, lightWithGO->getLightIntensity());
}

TEST_F(LightTest, TestDefaultLightColor) {
    auto color = light->getLightColor();
    auto colorGO = lightWithGO->getLightColor();
    ASSERT_FLOAT_EQ(1, color.x);
    ASSERT_FLOAT_EQ(1, color.y);
    ASSERT_FLOAT_EQ(1, color.z);
    ASSERT_FLOAT_EQ(1, colorGO.x);
    ASSERT_FLOAT_EQ(1, colorGO.y);
    ASSERT_FLOAT_EQ(1, colorGO.z);
}

TEST_F(LightTest, TestDefaultLightStruct) {
    auto lightStructGO = lightWithGO->getLightStruct();

    ASSERT_EQ(LightType::Point, lightStructGO.type);

    auto dirGO = lightStructGO.direction;
    ASSERT_FLOAT_EQ(1, dirGO.x);
    ASSERT_FLOAT_EQ(0, dirGO.y);
    ASSERT_FLOAT_EQ(0, dirGO.z);

    auto positionGO = lightStructGO.position;
    ASSERT_FLOAT_EQ(0, positionGO.x);
    ASSERT_FLOAT_EQ(0, positionGO.y);
    ASSERT_FLOAT_EQ(0, positionGO.z);

    ASSERT_FLOAT_EQ(1, lightStructGO.range);
    ASSERT_FLOAT_EQ(M_PI_2, lightStructGO.spotAngle);
    ASSERT_FLOAT_EQ(1, lightStructGO.intensity);

    auto colorGO = lightStructGO.color;
    ASSERT_FLOAT_EQ(1, colorGO.x);
    ASSERT_FLOAT_EQ(1, colorGO.y);
    ASSERT_FLOAT_EQ(1, colorGO.z);

}

void LightTest::SetUp() {
    light = Light::createLight();
    goWithLight = Light::createLightObject();
    lightWithGO = goWithLight->GetComponent<Light>();
}

void LightTest::TearDown() {}