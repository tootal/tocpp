#include <iostream>
#include "list.h"

int main() {
    ListNode *list = create_list(1, 2, 3, 4);
    std::cout << list << std::endl;
    return 0;
}