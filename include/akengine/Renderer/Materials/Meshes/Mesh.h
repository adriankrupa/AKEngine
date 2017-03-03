//
// Created by Adrian Krupa on 02.03.2017.
//

#ifndef AKENGINE_MESH_H
#define AKENGINE_MESH_H

#include <glbinding/gl/gl.h>
#include <vector>
#include "Vertex.h"

class Mesh {

    gl::GLuint VAO;

    gl::GLuint indexBuffer;
    gl::GLuint vertexBuffer;

    gl::GLuint allocatedIndexBuffer = 0;
    gl::GLuint allocatedVertexBuffer = 0;

public:
    virtual unsigned int *GetIndexData() = 0;

    virtual unsigned int GetIndexDataSize() = 0;

    virtual Vertex *GetVertexData() = 0;

    virtual unsigned int GetVertexDataSize() = 0;

    virtual unsigned int GetIndexDrawSize() = 0;

    virtual gl::GLenum GetDrawType() = 0;

    virtual ~Mesh();

    void setVertices(std::vector<Vertex> vertices);

    char GetMeshChangeHash();

    void FillData();
protected:
    std::vector<Vertex> vertices;
    char meshChangeCounter = 0;
    char meshHash = 0;
    std::string name;
    Mesh();
private:
    void GenerateBuffers();
};


#endif //AKENGINE_MESH_H
