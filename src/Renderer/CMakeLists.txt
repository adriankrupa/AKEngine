cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(SOURCE_FILES AKEngine.cpp ../include/akengine/AKEngine.h)

add_library(AKEngine ${SOURCE_FILES})

add_dependencies(AKEngine glm)
add_dependencies(AKEngine glfw)
add_dependencies(AKEngine glbinding)
add_dependencies(AKEngine spdlog)

target_link_libraries(AKEngine ${glfw_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glfw3${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(AKEngine ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_DEBUG_POSTFIX}${CMAKE_STATIC_LIBRARY_SUFFIX})

if (UNIX AND NOT APPLE)
    target_link_libraries(AKEngine dl X11 pthread GL m GLU Xrandr Xi Xxf86vm Xcursor Xinerama)
endif (UNIX AND NOT APPLE)

if (APPLE)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
    FIND_LIBRARY(IOKit_LIBRARY IOKit)
    FIND_LIBRARY(CORE_VIDEO_LIBRARY CoreVideo)

    message("COCOA_LIBRARY=${COCOA_LIBRARY}")
    message("OPENGL_LIBRARY=${OPENGL_LIBRARY}")
    message("IOKit_LIBRARY=${IOKit_LIBRARY}")
    message("CORE_VIDEO_LIBRARY=${CORE_VIDEO_LIBRARY}")

    target_link_libraries(AKEngine ${COCOA_LIBRARY})
    target_link_libraries(AKEngine ${OPENGL_LIBRARY})
    target_link_libraries(AKEngine ${IOKit_LIBRARY})
    target_link_libraries(AKEngine ${CORE_VIDEO_LIBRARY})
endif (APPLE)

if (WIN32)
    target_link_libraries(AKEngine opengl32)
endif (WIN32)