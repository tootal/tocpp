#include <iostream>
#include <vector>

#include "to_string.h"

int main() {
    std::cout << std::make_pair(std::make_pair("abc", 3), 2) << std::endl;
    std::cout << std::vector{1, 2, 3} << std::endl;
    std::cout << std::vector{"12", "3", "45"} << std::endl;
    return 0;
}