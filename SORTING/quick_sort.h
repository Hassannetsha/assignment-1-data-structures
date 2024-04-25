#ifndef ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H

#include <algorithm>
#include "../Student.h"

using namespace std;

template<typename t>
int partition(vector<t> &arr, int l, int h,int& comparisons) {
    t p = arr[l];
    int i = l;
    int j = h;
    while (i < j) {
        //sees first numbers smaller than pivot
        do {
            i++;
            comparisons++;
        } while (i < h && arr[i] <= p);
        //sees first numbers greater than pivot
        do {
            j--;
            comparisons++;
        } while (j > 0 && arr[j] > p);
        //sees if i less than j and swaps them
        if (i < j) {
            swap(arr[i], arr[j]);
            comparisons++;
        }
        comparisons-=2;
    }
    //and then puts the pivot in the center between the smaller and the greater
    swap(arr[l], arr[j]);
    return j;
}

template<typename t>
void quick_sort(vector<t> &arr, int l, int h,int& comparisons) {
    int j;
    if (l < h) {
        j = partition(arr, l, h,comparisons);
        quick_sort(arr, l, j,comparisons);
        quick_sort(arr, j + 1, h,comparisons);
    }
}

#endif //ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
