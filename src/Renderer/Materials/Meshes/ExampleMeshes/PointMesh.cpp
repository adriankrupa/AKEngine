//
// Created by Adrian Krupa on 02.03.2017.
//

#include "akengine/Renderer/Materials/Meshes/ExampleMeshes/PointMesh.h"
#include "akengine/Renderer/Materials/Meshes/Point.h"

using namespace glm;

PointMesh::PointMesh() : PointsMesh() {
    name = "PointMesh";
    Vertex v;
    v.normal = vec3(0.0f, 1.0f, 0.0f);
    v.color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    v.position = vec3(0, 0, 0);
    Point p;
    p.indices.a = 0;
    vertices.push_back(v);
    points.push_back(p);
}
