#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <cstdlib>

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