//
// Created by akrupa on 2017-02-24.
//

#include <algorithm>
#include <glbinding/gl/gl.h>
#include <akengine/Utilities/GLDebug.h>
#include <glm/gtc/type_ptr.hpp>

#include "akengine/Renderer/Materials/Material.h"
#include "akengine/Renderer/Materials/Shaders/Shader.h"

using namespace glm;
using namespace std;
using namespace gl;

Material::Material(std::shared_ptr<Shader> shader) {

    this->shader = shader;
    Material::lastAppliedMaterial = nullptr;
    SetVector("Color", vec4(1, 1, 1, 1), false);

    matrices_built_in.push_back(
            make_tuple("MATRIX_MVP", shader->getUniformLocation("MATRIX_MVP", false), mat4(), true));
    matrices_built_in.push_back(make_tuple("MATRIX_MV", shader->getUniformLocation("MATRIX_MV", false), mat4(), true));
    matrices_built_in.push_back(make_tuple("MATRIX_M", shader->getUniformLocation("MATRIX_M", false), mat4(), true));
    matrices_built_in.push_back(make_tuple("MATRIX_V", shader->getUniformLocation("MATRIX_V", false), mat4(), false));
    matrices_built_in.push_back(make_tuple("MATRIX_P", shader->getUniformLocation("MATRIX_P", false), mat4(), false));
    matrices_built_in.push_back(make_tuple("MATRIX_VP", shader->getUniformLocation("MATRIX_VP", false), mat4(), false));
    matrices_built_in.push_back(
            make_tuple("MATRIX_IT_MV", shader->getUniformLocation("MATRIX_IT_MV", false), mat4(), true));
    matrices_built_in.push_back(
            make_tuple("MATRIX_T_MV", shader->getUniformLocation("MATRIX_T_MV", false), mat4(), true));
    matrices_built_in.push_back(
            make_tuple("NormalMatrix", shader->getUniformLocation("NormalMatrix", false), mat4(), true));
}

void Material::ResetMaterial() {
    lastAppliedMaterial = nullptr;
}

void Material::ApplyMaterial() {
    Material *lastAppliedMaterial = Material::lastAppliedMaterial;
    if (Material::lastAppliedMaterial != this) {
        GL_CHECK(glUseProgram(this->shader->getProgram()));
        Material::lastAppliedMaterial = this;
    }

    for (const auto &val : vectors) {
        if (get<3>(val)) {
            GL_CHECK(glUniform4fv(get<1>(val), 1, value_ptr(get<2>(val))));
        }
    }

    for (const auto &val : floats) {
        if (get<3>(val)) {
            GL_CHECK(glUniform1fv(get<1>(val), 1, &get<2>(val)));
        }
    }

    for (const auto &val : integers) {
        if (get<3>(val)) {
            GL_CHECK(glUniform1iv(get<1>(val), 1, &get<2>(val)));
        }
    }

    for (const auto &val : matrices) {
        if (get<3>(val)) {
            GL_CHECK(glUniformMatrix4fv(get<1>(val), 1, GL_FALSE, value_ptr(get<2>(val))));
        }
    }

    for (const auto &val : matrices_built_in) {
        if (get<3>(val) && get<1>(val) >= 0) {
            GL_CHECK(glUniformMatrix4fv(get<1>(val), 1, GL_FALSE, value_ptr(get<2>(val))));
        }
    }

//    for (short i = 0; i < (short) textures.size(); i++) {
//        if (get<3>(textures[i])) {
//            GL_CHECK(glActiveTexture((GLenum) (GL_TEXTURE0 + i)));
//            TextureManager::getInstance().BindTexture(get<2>(textures[i]));
//            GL_CHECK(glUniform1i(get<1>(textures[i]), i));
//        }
//    }

    if (lastAppliedMaterial == this) {
        return;
    }

    for (const auto &val : vectors) {
        GL_CHECK(glUniform4fv(get<1>(val), 1, value_ptr(get<2>(val))));
    }

    for (const auto &val : floats) {
        GL_CHECK(glUniform1fv(get<1>(val), 1, &get<2>(val)));
    }

    for (const auto &val : integers) {
        GL_CHECK(glUniform1iv(get<1>(val), 1, &get<2>(val)));
    }

    for (const auto &val : matrices) {
        GL_CHECK(glUniformMatrix4fv(get<1>(val), 1, GL_FALSE, value_ptr(get<2>(val))));
    }

    for (const auto &val : matrices_built_in) {
        if (get<1>(val) >= 0) {
            GL_CHECK(glUniformMatrix4fv(get<1>(val), 1, GL_FALSE, value_ptr(get<2>(val))));
        }
    }

//    for (short i = 0; i < (short) textures.size(); i++) {
//        GL_CHECK(glActiveTexture((GLenum) (GL_TEXTURE0 + i)));
//        TextureManager::getInstance().BindTexture(get<2>(textures[i]));
//        GL_CHECK(glUniform1i(get<1>(textures[i]), i));
//    }
}

void Material::ReleaseMaterial() {
    GL_CHECK(glUseProgram(0));
}

Shader *Material::GetShader() const {
    return nullptr;
}

glm::vec4 Material::GetColor() const {
    return GetColor("Color");
}

vec4 Material::GetColor(string const &uniformName) const {
    return GetVector(uniformName);
}

float Material::GetFloat(string const &uniformName) const {
    float values[1];
    GL_CHECK(glGetUniformfv(shader->getProgram(), shader->getUniformLocation(uniformName), values));
    return values[0];
}

int Material::GetInt(string const &uniformName) const {
    int values[1];
    GL_CHECK(glGetUniformiv(shader->getProgram(), shader->getUniformLocation(uniformName), values));
    return values[0];
}

mat4 Material::GetMatrix(string const &uniformName) const {
    float values[16];
    GL_CHECK(glGetUniformfv(shader->getProgram(), shader->getUniformLocation(uniformName), values));
    return (mat4) make_mat4(values);
}

vec4 Material::GetVector(string const &uniformName) const {
    float values[4];
    GL_CHECK(glGetUniformfv(shader->getProgram(), shader->getUniformLocation(uniformName), values));
    return vec4(values[0], values[1], values[2], values[3]);
}

void Material::SetColor(glm::vec4 const &value) {
    SetColor("Color", value);
}

void Material::SetColor(std::string const &uniformName, glm::vec4 const &value) {
    SetVector(uniformName, value);
}

void Material::SetFloat(std::string const &uniformName, float value, bool notifyMissingUniform, bool objectSpecific) {
    auto it = find_if(floats.begin(), floats.end(), [&uniformName](const tuple<string, GLint, float, bool> v) {return uniformName == get<0>(v); });
    if (it != floats.end()) {
        get<2>(*it) = value;
    }
    else {
        int uniformLocation = shader->getUniformLocation(uniformName, notifyMissingUniform);
        if (uniformLocation >= 0) {
            floats.push_back(make_tuple(uniformName, uniformLocation, value, objectSpecific));
        }
    }
}

void Material::SetInt(std::string const &uniformName, int value, bool notifyMissingUniform, bool objectSpecific) {
    auto it = find_if(integers.begin(), integers.end(), [&uniformName](const tuple<string, GLint, int, bool> v) {return uniformName == get<0>(v); });
    if (it != integers.end()) {
        get<2>(*it) = value;
    }
    else {
        int uniformLocation = shader->getUniformLocation(uniformName, notifyMissingUniform);
        if (uniformLocation >= 0) {
            integers.push_back(make_tuple(uniformName, uniformLocation, value, objectSpecific));
        }
    }
}

void Material::SetMatrix(std::string const &uniformName, glm::mat4 const &value, bool notifyMissingUniform,
                         bool objectSpecific) {
    auto it = find_if(matrices.begin(), matrices.end(), [&uniformName](const tuple<string, GLint, mat4 const&, bool> v) {return uniformName == get<0>(v); });
    if (it != matrices.end()) {
        get<2>(*it) = value;
    }
    else {
        int uniformLocation = shader->getUniformLocation(uniformName, notifyMissingUniform);
        if (uniformLocation >= 0) {
            matrices.push_back(make_tuple(uniformName, uniformLocation, value, objectSpecific));
        }
    }
}

void Material::SetVector(std::string const &uniformName, glm::vec4 const &value, bool notifyMissingUniform,
                         bool objectSpecific) {
    auto it = find_if(vectors.begin(), vectors.end(), [&uniformName](const tuple<string, GLint, vec4 const&, bool> v) {return uniformName == get<0>(v); });
    if (it != vectors.end()) {
        get<2>(*it) = value;
    }
    else {
        int uniformLocation = shader->getUniformLocation(uniformName, notifyMissingUniform);
        if (uniformLocation >= 0) {
            vectors.push_back(make_tuple(uniformName, uniformLocation, value, objectSpecific));
        }
    }
}

void
Material::SetTexture(std::string const &uniformName, Texture *value, bool notifyMissingUniform, bool objectSpecific) {
    auto it = find_if(textures.begin(), textures.end(), [&uniformName](const tuple<string, GLint, Texture*, bool> v) {return uniformName == get<0>(v); });
    if (it != textures.end()) {
        get<2>(*it) = value;
    }
    else {
        int uniformLocation = shader->getUniformLocation(uniformName, notifyMissingUniform);
        if (uniformLocation >= 0) {
            textures.push_back(make_tuple(uniformName, uniformLocation, value, objectSpecific));
        }
    }
}

bool Material::isUsingLight() {
    return shader->isUsingLight();
}

void Material::SetMatrix(SHADER_BUILT_IN_MATRIX_UNIFORM builtInUniform, glm::mat4 const &value) {
    get<2>(matrices_built_in[(int) builtInUniform]) = value;
}

bool Material::IsUsingMatrix(SHADER_BUILT_IN_MATRIX_UNIFORM builtInUniform) {
    return get<1>(matrices_built_in[(int) builtInUniform]) >= 0;
}
