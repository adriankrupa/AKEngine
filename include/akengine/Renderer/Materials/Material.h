//
// Created by akrupa on 2017-02-24.
//

#ifndef AKENGINE_MATERIAL_H
#define AKENGINE_MATERIAL_H

#include <memory>
#include <vector>
#include <tuple>
#include <glbinding/gl/types.h>
#include <glm/glm.hpp>

class Shader;
class Texture;

enum class SHADER_BUILT_IN_MATRIX_UNIFORM {
    MATRIX_MVP,
    MATRIX_MV,
    MATRIX_M,
    MATRIX_V,
    MATRIX_P,
    MATRIX_VP,
    MATRIX_IT_MV,
    MATRIX_T_MV,
    NormalMatrix
};

class Material {
    friend class MeshRenderer;

public:
    Material(std::shared_ptr<Shader> shader);

    static void ResetMaterial();

    void ApplyMaterial();

    void ReleaseMaterial();

    Shader *GetShader() const;

    glm::vec4 GetColor() const;

    glm::vec4 GetColor(std::string const& uniformName) const;

    float GetFloat(std::string const& uniformName) const;

    int GetInt(std::string const& uniformName) const;

    glm::mat4 GetMatrix(std::string const& uniformName) const;

    glm::vec4 GetVector(std::string const& uniformName) const;

    void SetColor(glm::vec4 const& value);

    void SetColor(std::string const& uniformName, glm::vec4 const& value);

    void SetFloat(std::string const& uniformName, float value, bool notifyMissingUniform = true, bool objectSpecific = false);

    void SetInt(std::string const& uniformName, int value, bool notifyMissingUniform = true, bool objectSpecific = false);

    void SetMatrix(std::string const& uniformName, glm::mat4 const& value, bool notifyMissingUniform = true, bool objectSpecific = false);

    void SetVector(std::string const& uniformName, glm::vec4 const& value, bool notifyMissingUniform = true, bool objectSpecific = false);

    void SetTexture(std::string const& uniformName, Texture *value, bool notifyMissingUniform = true, bool objectSpecific = false);

    bool isUsingLight();
private:
    std::shared_ptr<Shader> shader;
    // string - uniform name
    // GLinit - uniform position
    // value
    // bool - object specific uniform
    std::vector<std::tuple<std::string, gl::GLint, glm::vec4, bool>>vectors;
    std::vector<std::tuple<std::string, gl::GLint, float, bool>>floats;
    std::vector<std::tuple<std::string, gl::GLint, int, bool>>integers;
    std::vector<std::tuple<std::string, gl::GLint, glm::mat4, bool>>matrices;
    std::vector<std::tuple<std::string, gl::GLint, Texture *, bool>>textures;

    std::vector<std::tuple<std::string, gl::GLint, glm::mat4, bool>>matrices_built_in;

    static Material* lastAppliedMaterial;

    void SetMatrix(SHADER_BUILT_IN_MATRIX_UNIFORM builtInUniform, glm::mat4 const& value);

    bool IsUsingMatrix(SHADER_BUILT_IN_MATRIX_UNIFORM builtInUniform);
};


#endif //AKENGINE_MATERIAL_H
