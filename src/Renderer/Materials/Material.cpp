//
// Created by akrupa on 2017-02-24.
//

#include "akengine/Renderer/Materials/Material.h"

Material::Material(std::shared_ptr<Shader> shader) {

    this->shader = shader;
//    Material::lastAppliedMaterial = nullptr;
//    SetVector("Color", vec4(1, 1, 1, 1), false);
}