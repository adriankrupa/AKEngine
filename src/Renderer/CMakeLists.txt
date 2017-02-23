cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

set(SOURCE_FILES
        Renderer.cpp ../../include/akengine/Renderer/Renderer.h
        GameObject.cpp ../../include/akengine/Renderer/GameObject.h
        Scene.cpp ../../include/akengine/Renderer/Scene.h)

add_subdirectory(Components)


add_library(Renderer ${SOURCE_FILES})
target_link_libraries(Renderer ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(Renderer Components)

add_dependencies(Renderer glm)
add_dependencies(Renderer glfw)
add_dependencies(Renderer glbinding)
add_dependencies(Renderer spdlog)

add_dependencies(Renderer Components)


