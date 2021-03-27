#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <cstdlib>

// 产生随机整数数列
// 根据随机数种子seed，生成大小为n的范围在[low, high]的随机整数列。
template <int seed = 1008, int low = 0, int high = 100>
std::vector<int> randlist(size_t n = 10) {
    srand(seed);
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = rand() % (high - low + 1) + low;
    }
    return res;
}

#endif // RANDOM