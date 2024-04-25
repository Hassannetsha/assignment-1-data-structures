#ifndef ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H

#include <algorithm>
#include "../Student.h"

using namespace std;

template<typename t>
int partition(vector<t> &arr, int l, int h) {
    t p = arr[l];
    int i = l;
    int j = h;
    while (i < j) {
        do {
            i++;
        } while (i < h && arr[i] <= p);
        do {
            j--;
        } while (j > 0 && arr[j] > p);

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename t>
void quick_sort(vector<t> &arr, int l, int h) {
    int j;
    if (l < h) {
        j = partition(arr, l, h);
        quick_sort(arr, l, j);
        quick_sort(arr, j + 1, h);
    }
}

#endif //ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
