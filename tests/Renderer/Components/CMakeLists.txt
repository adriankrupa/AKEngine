cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES ComponentTest.cpp ComponentTest.h TransformTest.cpp TransformTest.h)

add_library(ComponentsTest ${SOURCE_FILES})

add_dependencies(ComponentsTest glm)
add_dependencies(ComponentsTest spdlog)


