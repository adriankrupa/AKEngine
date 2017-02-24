//
// Created by akrupa on 2017-02-24.
//

#ifndef AKENGINE_MATERIAL_H
#define AKENGINE_MATERIAL_H

#include <memory>

class Shader;

class Material {
    friend class MeshRenderer;

public:
    Material(std::shared_ptr<Shader> shader);

private:
    std::shared_ptr<Shader> shader;
};


#endif //AKENGINE_MATERIAL_H
