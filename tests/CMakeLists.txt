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

add_subdirectory(Renderer)

set(SOURCE_FILES main.cpp)

add_executable(all_tests ${SOURCE_FILES})

target_link_libraries(all_tests ${gtest_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(all_tests RendererTest)

add_dependencies(all_tests AKEngine)
