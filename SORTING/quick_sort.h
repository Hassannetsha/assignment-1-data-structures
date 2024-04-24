#ifndef ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H

#include <algorithm>
#include "../Student.h"

using namespace std;

template<typename t>
int partition(vector<t> &arr, int l, int h, int choice) {
    t pivot = arr[l];
    int i = l, j = h;
    do {
        do { i++; }
        while (i < h-1 && ((!choice && arr[i].getGpa() <= pivot.getGpa())||
               (choice && arr[i] <= pivot)));
        do { j--; }
        while (j> 0 &&(!choice && arr[j].getGpa() > pivot.getGpa()) ||
               (choice && arr[j] > pivot));
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[l], arr[j]);
    return j;
}

template<typename t>
void quick_sort(vector<t> &arr, int l, int h, int choice) {
    int j;
    if (l < h) {
        j = partition(arr, l, h, choice);
        quick_sort(arr, l, j, choice);
        quick_sort(arr, j + 1, h, choice);
    }
}

#endif //ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
