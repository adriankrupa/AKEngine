cmake_minimum_required(VERSION 3.6)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

############# GLM #############

set(glm_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/glm" CACHE INTERNAL "" FORCE)
set(glm_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glm" CACHE INTERNAL "" FORCE)
set(glm_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/glm/include" CACHE INTERNAL "" FORCE)
set(glm_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${glm_INSTALL_DIR})

message("glm_PREFIX='${glm_PREFIX}'")
message("glm_INSTALL_DIR='${glm_INSTALL_DIR}'")
message("glm_INCLUDE_DIR='${glm_INCLUDE_DIR}'")
message("glm_CMAKE_ARGS='${glm_CMAKE_ARGS}'")

ExternalProject_Add(glm
        PREFIX ${glm_PREFIX}
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        INSTALL_DIR ${glm_INSTALL_DIR}
        CMAKE_ARGS ${glm_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )

############# GLFW #############

set(glfw_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glfw CACHE INTERNAL "" FORCE)
set(glfw_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glfw" CACHE INTERNAL "" FORCE)
set(glfw_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/glfw/include" CACHE INTERNAL "" FORCE)
set(glfw_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${glfw_INSTALL_DIR} -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF -DBUILD_SHARED_LIBS=OFF)

message("glfw_PREFIX='${glfw_PREFIX}'")
message("glfw_INSTALL_DIR='${glfw_INSTALL_DIR}'")
message("glfw_INCLUDE_DIR='${glfw_INCLUDE_DIR}'")
message("glfw_CMAKE_ARGS='${glfw_CMAKE_ARGS}'")

ExternalProject_Add(glfw
        PREFIX ${glfw_PREFIX}
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        INSTALL_DIR ${glfw_INSTALL_DIR}
        CMAKE_ARGS ${glfw_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )

############# GLBINDING #############

set(glbinding_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/glbinding" CACHE INTERNAL "" FORCE)
set(glbinding_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glbinding" CACHE INTERNAL "" FORCE)
set(glbinding_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/glbinding/include" CACHE INTERNAL "" FORCE)
set(glbinding_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${glbinding_INSTALL_DIR} -DOPTION_BUILD_TESTS=OFF -DOPTION_BUILD_GPU_TESTS=OFF -DOPTION_BUILD_TOOLS=OFF -DBUILD_SHARED_LIBS=OFF)

message("glbinding_PREFIX='${glbinding_PREFIX}'")
message("glbinding_INSTALL_DIR='${glbinding_INSTALL_DIR}'")
message("glbinding_INCLUDE_DIR='${glbinding_INCLUDE_DIR}'")
message("glbinding_CMAKE_ARGS='${glbinding_CMAKE_ARGS}'")

ExternalProject_Add(glbinding
        PREFIX ${glbinding_PREFIX}
        GIT_REPOSITORY https://github.com/cginternals/glbinding.git
        INSTALL_DIR ${glbinding_INSTALL_DIR}
        CMAKE_ARGS ${glbinding_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )

############# SPDLOG #############

set(spdlog_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/spdlog" CACHE INTERNAL "" FORCE)
set(spdlog_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/spdlog" CACHE INTERNAL "" FORCE)
set(spdlog_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/spdlog/include" CACHE INTERNAL "" FORCE)
set(spdlog_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${spdlog_INSTALL_DIR})

message("spdlog_PREFIX='${spdlog_PREFIX}'")
message("spdlog_INSTALL_DIR='${spdlog_INSTALL_DIR}'")
message("spdlog_INCLUDE_DIR='${spdlog_INCLUDE_DIR}'")
message("spdlog_CMAKE_ARGS='${spdlog_CMAKE_ARGS}'")

ExternalProject_Add(spdlog
        PREFIX ${spdlog_PREFIX}
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        INSTALL_DIR ${spdlog_INSTALL_DIR}
        CMAKE_ARGS ${spdlog_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )