#ifndef ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
#include <algorithm>
using namespace std;
int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l, j = h;
    do {
        do { i++; } while (arr[i] <= pivot);
        do { j--; } while (arr[j] > pivot);
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[l], arr[j]);
    return j;
}
void quick_sort(int arr[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(arr, l, h);
        quick_sort(arr, l, j);
        quick_sort(arr, j + 1, h);
    }
}
#endif //ASSIGNMENT_DATA_STRUCTURES_QUICK_SORT_H
