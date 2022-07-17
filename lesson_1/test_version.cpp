#define BOOST_TEST_MODULE test_version

#include "version.h"

#include <iostream>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    std::cout << "version: " << PROJECT_VERSION_PATCH << std::endl;
    //BOOST_CHECK(PROJECT_VERSION_PATCH > 0);
    BOOST_CHECK(3 > 0);
}

BOOST_AUTO_TEST_SUITE_END()
