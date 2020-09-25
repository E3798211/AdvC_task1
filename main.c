
#include <iostream>
#include "counting_int.h"

#include <algorithm>
#include <vector>

int main()
{
    std::vector<CountingInt> v = { 5, 3, 4, 7, 2, 1, 6, 4, 3 };
    // std::vector<CountingInt> v = { 9,8,7,6,5,4,3,2,1 };
    std::sort(v.begin(), v.end());
    int cmp = 0;
    int assign = 0;
    for (auto &a : v) {
        cmp += a.times_compared_against();
        assign += a.times_assigned();
    }
    std::cout << cmp << " " << assign << "\n";
}

