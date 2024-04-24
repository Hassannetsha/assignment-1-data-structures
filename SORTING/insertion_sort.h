#ifndef ASSIGNMENT_DATA_STRUCTURES_INSERTION_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_INSERTION_SORT_H
#include "../Student.h"

using namespace std;
template <typename t>
void insertion_sort(vector<t>& arr, int n,int choice) {
    for (int i = 1; i < n; i++)
    {
        t temp = arr[i];
        int j = i - 1;
        while (j > -1 && ((!choice && temp.getGpa() < arr[j].getGpa())||(choice && temp < arr[j]))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
#endif
