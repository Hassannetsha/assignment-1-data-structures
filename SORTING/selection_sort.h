#ifndef ASSIGNMENT_DATA_STRUCTURES_SELECTION_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_SELECTION_SORT_H
#include "../Student.h"
template <typename t>
void selection(vector<t>& arr, int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n ; j++) {
            int min = i;
            if (arr[j] < arr[min])
                min = j;
            swap(arr[min],arr[i]);
        }
    }
}
#endif //ASSIGNMENT_DATA_STRUCTURES_SELECTION_SORT_H
