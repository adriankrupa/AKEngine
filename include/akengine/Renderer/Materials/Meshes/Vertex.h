//
// Created by Adrian Krupa on 02.03.2017.
//

#ifndef AKENGINE_VERTEX_H
#define AKENGINE_VERTEX_H

#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 position;
    glm::vec3 tangent;
    glm::vec2 UV;
    glm::vec3 normal;
    glm::vec4 color;
};

struct VertexParticleSystem {
    glm::vec3 position;
};

#endif //AKENGINE_VERTEX_H
