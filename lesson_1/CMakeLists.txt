cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.1.${PATCH_VERSION})
set(BOOST_TEST_MODULE test_version)
set(BOOST_TEST_MODULE_STRING "${BOOST_TEST_MODULE}")

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
    if(DEB_PACKAGE_ENABLE)
        install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
        set(CPACK_GENERATOR DEB)
        set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
        set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
        set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
        set(CPACK_PACKAGE_CONTACT karasev.ia@phystech.edu)
        include(CPack)
    endif()
endif()

if(TEST_ENABLE)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(${BOOST_TEST_MODULE} test_version.cpp)
    target_link_libraries(${BOOST_TEST_MODULE} ${Boost_LIBRARIES})
    set_target_properties(${BOOST_TEST_MODULE} PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )
    target_include_directories(${BOOST_TEST_MODULE} PRIVATE "${CMAKE_BINARY_DIR}")
    if (MSVC)
        target_compile_options(${BOOST_TEST_MODULE} PRIVATE
            /W4
        )
    else ()
        target_compile_options(${BOOST_TEST_MODULE} PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
    add_test(${BOOST_TEST_MODULE} ${BOOST_TEST_MODULE})
    enable_testing()
endif()