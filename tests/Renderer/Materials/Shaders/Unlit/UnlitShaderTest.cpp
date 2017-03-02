//
// Created by Adrian Krupa on 28.02.2017.
//

#include <akengine/AKEngine.h>
#include <glbinding/gl/gl.h>

#include "UnlitShaderTest.h"

using namespace std;
using namespace gl;

TEST_F(UnlitShaderTest, TestShader) {
    EXPECT_NE(nullptr, shader);
}

void UnlitShaderTest::SetUp() {
    engine = make_shared<AKEngine>();
    engine->init();
    engine->createHeadlessWindow();

    shader = make_shared<UnlitShader>();
    shader->setup();
}

void UnlitShaderTest::TearDown() {
    engine->destroyWindow();
}
