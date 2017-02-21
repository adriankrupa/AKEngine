cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES Renderer.cpp ../../include/akengine/Renderer/Renderer.h)

add_library(Renderer ${SOURCE_FILES})
target_link_libraries(Renderer ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})


