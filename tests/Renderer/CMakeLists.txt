cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES RendererTest.cpp RendererTest.h)

add_subdirectory(Components)


add_library(RendererTest ${SOURCE_FILES})
target_link_libraries(RendererTest ComponentsTest)

add_dependencies(RendererTest ComponentsTest)

add_dependencies(RendererTest Renderer)
