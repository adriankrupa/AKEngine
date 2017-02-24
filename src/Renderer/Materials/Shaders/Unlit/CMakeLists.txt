cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})

set(SOURCE_FILES "")

add_library(UnlitShaders ${SOURCE_FILES})

add_dependencies(UnlitShaders glm)
add_dependencies(UnlitShaders spdlog)
add_dependencies(UnlitShaders glbinding)

target_link_libraries(UnlitShaders ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})



