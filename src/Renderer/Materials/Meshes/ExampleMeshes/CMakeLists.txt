cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES PointMesh.cpp ../../../../../include/akengine/Renderer/Materials/Meshes/ExampleMeshes/PointMesh.h)

add_library(ExampleMeshes ${SOURCE_FILES})

add_dependencies(ExampleMeshes glm)

target_link_libraries(ExampleMeshes ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})
