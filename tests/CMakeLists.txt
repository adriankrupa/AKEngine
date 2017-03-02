cmake_minimum_required(VERSION 3.6)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

############# GLM #############

set(gtest_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/gtest" CACHE INTERNAL "" FORCE)
set(gtest_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/gtest" CACHE INTERNAL "" FORCE)
set(gtest_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/gtest/include" CACHE INTERNAL "" FORCE)
set(gtest_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${gtest_INSTALL_DIR})

message("gtest_PREFIX='${gtest_PREFIX}'")
message("gtest_INSTALL_DIR='${gtest_INSTALL_DIR}'")
message("gtest_INCLUDE_DIR='${gtest_INCLUDE_DIR}'")
message("gtest_CMAKE_ARGS='${gtest_CMAKE_ARGS}'")

ExternalProject_Add(gtest
        PREFIX ${gtest_PREFIX}
        GIT_REPOSITORY https://github.com/google/googletest.git
        INSTALL_DIR ${gtest_INSTALL_DIR}
        CMAKE_ARGS ${gtest_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )

include_directories(${gtest_INCLUDE_DIR})

set(SOURCE_FILES main.cpp
        Renderer/RendererTest.h Renderer/RendererTest.cpp
        Renderer/Components/ComponentTest.h Renderer/Components/ComponentTest.cpp
        Renderer/Components/TransformTest.h Renderer/Components/TransformTest.cpp
        Renderer/GameObjectTest.h Renderer/GameObjectTest.cpp
        Renderer/Components/LightTest.h Renderer/Components/LightTest.cpp
        Renderer/Materials/Shaders/ShaderTest.h Renderer/Materials/Shaders/ShaderTest.cpp Renderer/Materials/Shaders/SurfaceShaderTest.cpp Renderer/Materials/Shaders/SurfaceShaderTest.h Renderer/Materials/Shaders/Unlit/UnlitShaderTest.cpp Renderer/Materials/Shaders/Unlit/UnlitShaderTest.h)

add_executable(all_tests ${SOURCE_FILES})

add_dependencies(all_tests AKEngine)
add_dependencies(all_tests gtest)

target_link_libraries(all_tests ${gtest_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(all_tests AKEngine)


