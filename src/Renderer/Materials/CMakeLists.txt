cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

set(SOURCE_FILES "" Material.cpp ../../../include/akengine/Renderer/Materials/Material.h)

add_library(Materials ${SOURCE_FILES})

add_dependencies(Materials glm)
add_dependencies(Materials spdlog)
add_dependencies(Materials glbinding)

add_subdirectory(Shaders)

add_dependencies(Materials Shaders)

target_link_libraries(Materials ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(Materials Shaders)


