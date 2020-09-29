
#ifndef   SORT_H_INCLUDED
#define   SORT_H_INCLUDED

#include <algorithm>
#include <vector>

namespace sorts 
{

template <typename T> using sort_t = void (*)(std::vector<T>&);

template<typename T>
void bubble(std::vector<T> &arr) {
    for (std::size_t i = 0; i < arr.size(); i++)
        for (std::size_t k = 0; k < arr.size() - 1 - i; k++)
            if (arr[k + 1] < arr[k]) {
                T tmp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = tmp;
            }
}

template<typename T>
void stdsort(std::vector<T> &arr) {
    std::sort(arr.begin(), arr.end());
}

}

#endif // SORT_H_INCLUDED

