cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)
add_executable(helloworld helloworld.cpp)
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)