#include <iostream>
#include "version.h"

int main()
{
    std::cout << int(PROJECT_VERSION_PATCH) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}