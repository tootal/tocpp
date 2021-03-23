#include <iostream>

#include "range.h"

int main() {
    std::cout << range(5) << std::endl;
    std::cout << range(5, 10) << std::endl;
    std::cout << range(5, 10, 2) << std::endl;
    std::cout << range(5, 1, -2) << std::endl;
    return 0;
}