//
// Created by akrupa on 2017-02-21.
//

#include "TransformTest.h"


TEST_F(TransformTest, TestDefaultPosition) {
    ASSERT_EQ(transform ->getPosition(), glm::vec3(0,0,0));
}

TEST_F(TransformTest, TestDefaultRotation) {
    ASSERT_EQ(transform ->getRotation(), glm::quat(1,0,0,0));
}

TEST_F(TransformTest, TestDefaultRotationInEulerAngles) {
    ASSERT_EQ(transform ->getRotationInEulerAngles(), glm::vec3(0,0,0));
}

TEST_F(TransformTest, TestDefaultScale) {
    ASSERT_EQ(transform ->getScale(), glm::vec3(1,1,1));
}

TEST_F(TransformTest, TestDefaultModelMatrix) {
    ASSERT_EQ(transform ->getModelMatrix(), glm::mat4(glm::vec4(1,0,0,0), glm::vec4(0,1,0,0), glm::vec4(0,0,1,0), glm::vec4(0,0,0,1)));
}

TEST_F(TransformTest, TestDefaultNormalMatrix) {
    ASSERT_EQ(transform ->getNormalMatrix(), glm::mat4(glm::vec4(1,0,0,0), glm::vec4(0,1,0,0), glm::vec4(0,0,1,0), glm::vec4(0,0,0,1)));
}

TEST_F(TransformTest, TestSetPosition) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f/3.0f);
    transform -> setPosition(pos);
    ASSERT_EQ(transform ->getPosition(), pos);
}

TEST_F(TransformTest, TestSetRotation) {
    auto axis = glm::vec3(30, -12, 2.0f/9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * sin(RotationAngle / 2);
    auto y = axis.y * sin(RotationAngle / 2);
    auto z = axis.z * sin(RotationAngle / 2);
    auto w = cos(RotationAngle / 2);

    auto s = sqrt(x*x+y*y+z*z+w*w);

    auto rotation = glm::quat(w/s, x/s, y/s, z/s);
    transform -> setRotation(rotation);
    ASSERT_EQ(transform ->getRotation(), rotation);
}

TEST_F(TransformTest, TestSetRotationInAngles) {

    auto pitch = 1.0f;
    auto roll = 0.5f;
    auto yaw = -3.0f;

    transform -> setRotation(glm::vec3(pitch, roll, yaw));
    ASSERT_EQ(transform ->getRotation(), glm::normalize(glm::quat(glm::vec3(pitch, roll, yaw))));
}

void TransformTest::SetUp() {
    transform = new Transform();
}

void TransformTest::TearDown() {
    delete transform;
}
