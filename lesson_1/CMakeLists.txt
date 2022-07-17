cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
set(BOOST_TEST_MODULE test_version)
set(BOOST_TEST_MODULE_STRING "${BOOST_TEST_MODULE}")

option(CLI_ENABLE "Main programm cli enable" ON)
option(TEST_ENABLE "Unit test enable" ON)

project(helloworld VERSION ${PROJECT_VESRION})
configure_file(version.h.in version.h)

if(CLI_ENABLE)
    add_executable(helloworld_cli helloworld.cpp)
    target_include_directories(helloworld_cli PRIVATE "${CMAKE_BINARY_DIR}")
    set_target_properties(helloworld_cli PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )
    if (MSVC)
        target_compile_options(helloworld_cli PRIVATE
            /W4
        )
    else ()
        target_compile_options(helloworld_cli PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

if(TEST_ENABLE)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_version test_version.cpp)
    target_link_libraries(test_version ${Boost_LIBRARIES})
    set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )
    target_include_directories(test_version PRIVATE "${CMAKE_BINARY_DIR}")
    if (MSVC)
        target_compile_options(test_version PRIVATE
            /W4
        )
    else ()
        target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
    enable_testing()
    add_test(test_version test_version)
endif()