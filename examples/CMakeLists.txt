cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES main.cpp)

add_executable(main ${SOURCE_FILES})

add_dependencies(main AKEngine)


target_link_libraries(main AKEngine)
