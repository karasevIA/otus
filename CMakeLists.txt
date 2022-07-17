cmake_minimum_required(VERSION 3.10)

project(OTUS VERSION 1.0)

option(CLI_ENABLE "Main programm cli enable" ON)
option(TEST_ENABLE "Unit test enable" ON)

if(TEST_ENABLE)
    set(BOOST_TEST_MODULE test_version)
endif()

add_subdirectory(lesson_1)

if(TEST_ENABLE)
    add_test(${BOOST_TEST_MODULE})
    enable_testing()
endif()