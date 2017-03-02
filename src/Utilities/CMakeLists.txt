cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

set(SOURCE_FILES
        GLDebug.cpp ../../include/akengine/Utilities/GLDebug.h
        WorkingDirectory.cpp ../../include/akengine/Utilities/WorkingDirectory.h)


add_library(Utilities ${SOURCE_FILES})

add_dependencies(Renderer glbinding)
add_dependencies(Renderer spdlog)


