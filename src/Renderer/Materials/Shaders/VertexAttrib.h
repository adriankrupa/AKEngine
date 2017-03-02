//
// Created by Adrian Krupa on 24.02.2017.
//

#ifndef AKENGINE_VERTEXATTRIB_H
#define AKENGINE_VERTEXATTRIB_H

#include <glbinding/gl/gl.h>

typedef enum : gl::GLuint {
    VertexAttribPosition,
    VertexAttribNormal,
    VertexAttribUV,
    VertexAttribTangent,
    VertexAttribColor
} VertexAttrib;

#endif //AKENGINE_VERTEXATTRIB_H
