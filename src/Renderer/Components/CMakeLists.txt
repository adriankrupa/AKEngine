cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

set(SOURCE_FILES
        Component.cpp ../../../include/akengine/Renderer/Components/Component.h
        Transform.cpp ../../../include/akengine/Renderer/Components/Transform.h
        Camera.cpp ../../../include/akengine/Renderer/Components/Camera.h
        Light.cpp ../../../include/akengine/Renderer/Components/Light.h)

add_library(Components ${SOURCE_FILES})

add_dependencies(Components glm)
add_dependencies(Components spdlog)
add_dependencies(Components glbinding)

target_link_libraries(Components ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})



