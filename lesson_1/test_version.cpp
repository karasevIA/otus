#include <iostream>
#include <boost/test/unit_test.hpp>

#include "version.h"

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    std::cout << "version: " << PROJECT_VERSION_PATCH << std::endl;
    BOOST_CHECK(int(PROJECT_VERSION_PATCH) > 0);
}

BOOST_AUTO_TEST_SUITE_END()
