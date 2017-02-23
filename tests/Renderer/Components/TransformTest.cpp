//
// Created by akrupa on 2017-02-21.
//

#include <akengine/Renderer/GameObject.h>
#include <akengine/Renderer/Components/Camera.h>
#include "TransformTest.h"

TEST_F(TransformTest, TestDefaultPosition) {
    ASSERT_EQ(transform->getPosition(), glm::vec3(0, 0, 0));
}

TEST_F(TransformTest, TestDefaultRotation) {
    ASSERT_EQ(transform->getRotation(), glm::quat(1, 0, 0, 0));
}

TEST_F(TransformTest, TestDefaultRotationInEulerAngles) {
    ASSERT_EQ(transform->getRotationInEulerAngles(), glm::vec3(0, 0, 0));
}

TEST_F(TransformTest, TestDefaultScale) {
    ASSERT_EQ(transform->getScale(), glm::vec3(1, 1, 1));
}

TEST_F(TransformTest, TestDefaultModelMatrix) {
    ASSERT_EQ(transform->getModelMatrix(),
              glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0), glm::vec4(0, 0, 0, 1)));
}

TEST_F(TransformTest, TestDefaultNormalMatrix) {
    ASSERT_EQ(transform->getNormalMatrix(),
              glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0), glm::vec4(0, 0, 0, 1)));
}

TEST_F(TransformTest, TestSetPosition) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    transform->setPosition(pos);
    ASSERT_EQ(transform->getPosition(), pos);
}

TEST_F(TransformTest, TestSetRotation) {
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto rotation = glm::quat(x / s, y / s, z / s, w / s);

    transform->setRotation(rotation);
    ASSERT_EQ(transform->getRotation(), rotation);
}

TEST_F(TransformTest, TestSetRotationInAngles) {

    auto pitch = 1.0f;
    auto roll = 0.5f;
    auto yaw = -3.0f;

    transform->setRotation(glm::vec3(pitch, roll, yaw));
    ASSERT_EQ(transform->getRotation(), glm::normalize(glm::quat(glm::vec3(pitch, roll, yaw))));
}

TEST_F(TransformTest, TestModelMatrixTranslation) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    transform->setPosition(pos);
    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrix = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                  glm::vec4(pos, 1));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestModelMatrixRotation) {
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setRotation(q);

    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrix = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestModelMatrixScale) {
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);
    transform->setScale(scale);
    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrix = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0), glm::vec4(0, 0, scale.z, 0),
                                  glm::vec4(0, 0, 0, 1));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestModelMatrixTranslationRotation) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setPosition(pos);
    transform->setRotation(q);

    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrixTranslation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                             glm::vec4(pos, 1));
    auto assertMatrixRotation = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    auto assertMatrix = assertMatrixTranslation * assertMatrixRotation;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestModelMatrixTranslationScale) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);

    transform->setPosition(pos);
    transform->setScale(scale);

    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrixTranslation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                             glm::vec4(pos, 1));
    auto assertMatrixScale = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0),
                                       glm::vec4(0, 0, scale.z, 0),
                                       glm::vec4(0, 0, 0, 1));
    auto assertMatrix = assertMatrixTranslation * assertMatrixScale;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestModelMatrixRotationScale) {
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setScale(scale);
    transform->setRotation(q);

    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrixRotation = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    auto assertMatrixScale = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0),
                                       glm::vec4(0, 0, scale.z, 0),
                                       glm::vec4(0, 0, 0, 1));
    auto assertMatrix = assertMatrixRotation * assertMatrixScale;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestModelMatrixTransformRotationScale) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setPosition(pos);
    transform->setScale(scale);
    transform->setRotation(q);

    auto modelMatrix = transform->getModelMatrix();
    auto assertMatrixRotation = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    auto assertMatrixScale = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0),
                                       glm::vec4(0, 0, scale.z, 0),
                                       glm::vec4(0, 0, 0, 1));
    auto assertMatrixTranslation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                             glm::vec4(pos, 1));
    auto assertMatrix = assertMatrixTranslation * assertMatrixRotation * assertMatrixScale;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(modelMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixTranslation) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    transform->setPosition(pos);
    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrix = glm::inverse(glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                               glm::vec4(pos, 1)));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixRotation) {
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setRotation(q);

    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrix = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    assertMatrix = glm::inverse(assertMatrix);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixScale) {
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);
    transform->setScale(scale);
    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrix = glm::inverse(
            glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0), glm::vec4(0, 0, scale.z, 0),
                      glm::vec4(0, 0, 0, 1)));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixTranslationRotation) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setPosition(pos);
    transform->setRotation(q);

    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrixTranslation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                             glm::vec4(pos, 1));
    auto assertMatrixRotation = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    auto assertMatrix = glm::inverse(assertMatrixTranslation * assertMatrixRotation);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixTranslationScale) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);

    transform->setPosition(pos);
    transform->setScale(scale);

    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrixTranslation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                             glm::vec4(pos, 1));
    auto assertMatrixScale = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0),
                                       glm::vec4(0, 0, scale.z, 0),
                                       glm::vec4(0, 0, 0, 1));
    auto assertMatrix = glm::inverse(assertMatrixTranslation * assertMatrixScale);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixRotationScale) {
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setScale(scale);
    transform->setRotation(q);

    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrixRotation = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    auto assertMatrixScale = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0),
                                       glm::vec4(0, 0, scale.z, 0),
                                       glm::vec4(0, 0, 0, 1));
    auto assertMatrix = glm::inverse(assertMatrixRotation * assertMatrixScale);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

TEST_F(TransformTest, TestViewMatrixTransformRotationScale) {
    auto pos = glm::vec3(-99, 12.455f, 1.0f / 3.0f);
    auto scale = glm::vec3(1.1f, 100, 9.0f / 17.0f);
    auto axis = glm::vec3(30, -12, 2.0f / 9.0f);
    auto RotationAngle = 3.5f;

    auto x = axis.x * glm::sin(RotationAngle / 2);
    auto y = axis.y * glm::sin(RotationAngle / 2);
    auto z = axis.z * glm::sin(RotationAngle / 2);
    auto w = glm::cos(RotationAngle / 2);
    auto s = glm::sqrt(x * x + y * y + z * z + w * w);
    auto q = glm::quat(x / s, y / s, z / s, w / s);

    transform->setPosition(pos);
    transform->setScale(scale);
    transform->setRotation(q);

    auto viewMatrix = transform->getViewMatrix();
    auto assertMatrixRotation = glm::mat4(
            glm::vec4(1 - 2 * q.y * q.y - 2 * q.z * q.z, 2 * q.x * q.y + 2 * q.z * q.w, 2 * q.x * q.z - 2 * q.y * q.w,
                      0),
            glm::vec4(2 * q.x * q.y - 2 * q.z * q.w, 1 - 2 * q.x * q.x - 2 * q.z * q.z, 2 * q.y * q.z + 2 * q.x * q.w,
                      0),
            glm::vec4(2 * q.x * q.z + 2 * q.y * q.w, 2 * q.y * q.z - 2 * q.x * q.w, 1 - 2 * q.x * q.x - 2 * q.y * q.y,
                      0),
            glm::vec4(0, 0, 0, 1));
    auto assertMatrixScale = glm::mat4(glm::vec4(scale.x, 0, 0, 0), glm::vec4(0, scale.y, 0, 0),
                                       glm::vec4(0, 0, scale.z, 0),
                                       glm::vec4(0, 0, 0, 1));
    auto assertMatrixTranslation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0), glm::vec4(0, 0, 1, 0),
                                             glm::vec4(pos, 1));
    auto assertMatrix = glm::inverse(assertMatrixTranslation * assertMatrixRotation * assertMatrixScale);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ASSERT_FLOAT_EQ(viewMatrix[i][j], assertMatrix[i][j]);
        }
    }
}

void TransformTest::SetUp() {
    transform = new Transform();
}

void TransformTest::TearDown() {
    delete transform;
}
