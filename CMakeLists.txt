cmake_minimum_required(VERSION 3.10)

project(OTUS VERSION 1.0)

option(LESSON_1 "Lesson 1 project run and test enable" ON)

if(LESSON_1)
    option(CLI_ENABLE "Main programm cli enable" ON)
    option(TEST_ENABLE "Unit test enable" ON)
    if(TEST_ENABLE)
        set(BOOST_TEST_MODULE test_version)
    endif()
    add_subdirectory(lesson_1)
endif()

if(TEST_ENABLE)
    enable_testing()
endif()