//
// Created by Adrian Krupa on 02.03.2017.
//

#ifndef AKENGINE_POINTSMESH_H
#define AKENGINE_POINTSMESH_H

#include "akengine/Renderer/Materials/Meshes/Mesh.h"

struct Point;

class PointsMesh : public Mesh {

protected:
    std::vector<Point> points;
    PointsMesh();

public:
    PointsMesh(std::vector<Vertex> points);
    virtual unsigned int *GetIndexData() override;
    virtual unsigned int GetIndexDataSize() override;

    virtual Vertex *GetVertexData() override;
    virtual unsigned int GetVertexDataSize() override;

    virtual unsigned int GetIndexDrawSize() override;

    virtual gl::GLenum GetDrawType() override;
};


#endif //AKENGINE_POINTSMESH_H
