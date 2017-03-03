//
// Created by Adrian Krupa on 02.03.2017.
//

#include "akengine/Renderer/Materials/Meshes/Point.h"
#include "akengine/Renderer/Materials/Meshes/PointsMesh.h"

using namespace std;
using namespace gl;

PointsMesh::PointsMesh() : Mesh() {
    points = vector<Point>();
}

PointsMesh::PointsMesh(vector<Vertex> points) : Mesh() {
    this->points = vector<Point>(points.size());
    Point p;
    for(size_t i=0; i < points.size(); ++i) {
        p.indices.a = (unsigned int)i;
        this->points.push_back(p);
    }
    this->vertices = points;
}

unsigned int *PointsMesh::GetIndexData() {
    return (unsigned int*)points.data();
}

unsigned int PointsMesh::GetIndexDataSize() {
    return (unsigned int)(points.size() * sizeof(Point));
}

Vertex *PointsMesh::GetVertexData() {
    return vertices.data();
}

unsigned int PointsMesh::GetVertexDataSize() {
    return (unsigned int)(vertices.size() * sizeof(Vertex));
}

unsigned int PointsMesh::GetIndexDrawSize() {
    return (unsigned int)points.size();
}

gl::GLenum PointsMesh::GetDrawType() {
    return GL_POINTS;
}
