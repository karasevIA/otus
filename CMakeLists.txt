cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.1.${PATCH_VERSION})

project(OTUS VERSION ${PROJECT_VESRION})

option(LESSON_1 "Lesson 1 project run and test enable" ON)

if(LESSON_1)
    option(CLI_ENABLE "Main programm cli enable" ON)
    option(TEST_ENABLE "Unit test enable" ON)
    option(DEB_PACKAGE_ENABLE "Debian packet generation enable" ON)
    add_subdirectory(lesson_1)
endif()

if(TEST_ENABLE)
    enable_testing()
endif()