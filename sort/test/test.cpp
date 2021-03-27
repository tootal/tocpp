// 测试各种排序算法的性能

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#include "sort/sort.h"

template <typename Iterator>
using sort_t = void(*)(Iterator, Iterator);
sort_t<std::vector<int>::iterator> sort;

void usage() {
    std::cout << "Usage: ./test [bubble|quick|std]" << std::endl;
    exit(0);
}

void test() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) usage();
    if (!strcmp(argv[1], "std")) {
        sort = &std::sort;
    } else if (!strcmp(argv[1], "bubble")) {
        sort = &bubble_sort;
    } else if (!strcmp(argv[1], "quick")) {
        sort = &quick_sort;
    } else {
        usage();
    }
    test();
    return 0;
}