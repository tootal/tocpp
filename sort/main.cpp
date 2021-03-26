#include <iostream>

#include "sort.h"
#include "random/random.h"
#include "string/to_string.h"

int main() {
    auto nums = randlist(10);
    
    std::cout << nums << '\n';
    return 0;
}
