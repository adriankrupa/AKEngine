cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(AKEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)



include_directories(${glfw_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})
include_directories(${glm_INCLUDE_DIR})

add_subdirectory(lib)
add_subdirectory(tests)

add_subdirectory(examples)
add_subdirectory(src)

#INSTALL(TARGETS AKEngine
#        DESTINATION lib
#        )
#INSTALL(DIRECTORY include DESTINATION .)



