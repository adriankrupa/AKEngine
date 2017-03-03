//
// Created by Adrian Krupa on 02.03.2017.
//

#include <akengine/Utilities/GLDebug.h>
#include "akengine/Renderer/Materials/Meshes/Mesh.h"
#include "../Shaders/VertexAttrib.h"

using namespace std;
using namespace gl;


Mesh::~Mesh() {

}

void Mesh::setVertices(std::vector<Vertex> vertices) {
    this->vertices = vertices;
    meshChangeCounter++;
}

char Mesh::GetMeshChangeHash() {
    return meshChangeCounter;
}

void Mesh::FillData() {
    GL_CHECK(glBindVertexArray(VAO));

    if (meshHash != GetMeshChangeHash()) {
        meshHash = GetMeshChangeHash();
    } else {
        return;
    }

    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
    GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer));
    uint vertexDataCount = GetVertexDataSize();
    if (vertexDataCount != allocatedVertexBuffer) {
        allocatedVertexBuffer = vertexDataCount;
        GL_CHECK(glBufferData(GL_ARRAY_BUFFER, vertexDataCount, GetVertexData(), GL_STATIC_DRAW));
    } else {
        GL_CHECK(glBufferSubData(GL_ARRAY_BUFFER, 0, allocatedVertexBuffer, GetVertexData()));
    }

    uint indexDataCount = GetIndexDataSize();
    if (indexDataCount != allocatedIndexBuffer) {
        allocatedIndexBuffer = indexDataCount;
        GL_CHECK(glBufferData(GL_ELEMENT_ARRAY_BUFFER, allocatedIndexBuffer, GetIndexData(), GL_STATIC_DRAW));
    } else {
        GL_CHECK(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, allocatedIndexBuffer, GetIndexData()));
    }
}

Mesh::Mesh() {
    vertices = vector<Vertex>();
    meshChangeCounter++;
    GenerateBuffers();
}

void Mesh::GenerateBuffers() {
    GL_CHECK(glGenVertexArrays(1, &VAO));
    GL_CHECK(glBindVertexArray(VAO));

    GL_CHECK(glGenBuffers(1, &vertexBuffer));
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
    GL_CHECK(glGenBuffers(1, &indexBuffer));
    GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer));

    GL_CHECK(glEnableVertexAttribArray(VertexAttribPosition));
    GL_CHECK(glVertexAttribPointer(VertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                   (void *) offsetof(Vertex, position)));

    GL_CHECK(glEnableVertexAttribArray(VertexAttribNormal));
    GL_CHECK(glVertexAttribPointer(VertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                   (void *) offsetof(Vertex, normal)));

    GL_CHECK(glEnableVertexAttribArray(VertexAttribTangent));
    GL_CHECK(glVertexAttribPointer(VertexAttribTangent, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                   (void *) offsetof(Vertex, tangent)));

    GL_CHECK(glEnableVertexAttribArray(VertexAttribColor));
    GL_CHECK(glVertexAttribPointer(VertexAttribColor, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                   (void *) offsetof(Vertex, color)));

    GL_CHECK(glEnableVertexAttribArray(VertexAttribUV));
    GL_CHECK(glVertexAttribPointer(VertexAttribUV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                                   (void *) offsetof(Vertex, UV)));
}
