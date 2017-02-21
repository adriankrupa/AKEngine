cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES Component.cpp ../../../include/akengine/Renderer/Components/Component.h Transform.cpp ../../../include/akengine/Renderer/Components/Transform.h)

add_library(Components ${SOURCE_FILES})

add_dependencies(Components glm)
add_dependencies(Components spdlog)



