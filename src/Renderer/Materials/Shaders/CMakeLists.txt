cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

set(SOURCE_FILES
        Shader.cpp ../../../../include/akengine/Renderer/Materials/Shaders/Shader.h
        SurfaceShader.cpp ../../../../include/akengine/Renderer/Materials/Shaders/SurfaceShader.h)

add_library(Shaders ${SOURCE_FILES})

add_dependencies(Shaders glm)
add_dependencies(Shaders spdlog)
add_dependencies(Shaders glbinding)

add_subdirectory(Unlit)

add_dependencies(Shaders UnlitShaders)

target_link_libraries(Shaders ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(Shaders UnlitShaders)



