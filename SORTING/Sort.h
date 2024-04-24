#ifndef ASSIGNMENT_DATA_STRUCTURES_SORT_H
#define ASSIGNMENT_DATA_STRUCTURES_SORT_H
#include "insertion_sort.h"
#include "selection_sort.h"
#include "quick_sort.h"
using namespace std;

template<typename t>
void Choosen_sort(int SortType,const string& type,vector<t>& arr, int choice){
    switch (SortType) {
        case 1:
            insertion_sort(arr,(int)arr.size(),choice);
            break;
        case 2:
            selection(arr,(int)arr.size(),choice);
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            quick_sort(arr,0,arr.size(),choice);
            break;
        case 7:
            break;
        default:
            cout<<"Wrong input\n";
            cout<<"Sort by: 1 - Insertion Sort\n"
                  "2- Selection Sort\n"
                  "3- Bubble Sort\n"
                  "4- Shell Sort\n"
                  "5- Merge Sort\n"
                  "6- Quick Sort\n";
            cin>>SortType;
            Choosen_sort(SortType,type,arr,choice);
    }
}

template<typename t>
void sort_students(vector<t>& arr){
    int choice,SortType;
    cout<<"1- sort by name  2- sort_students by GPA\n";
    cin>>choice;
    switch (choice) {
        case 1:
            choice = 1;
            cout<<"Sort by: 1 - Insertion Sort\n"
                  "2- Selection Sort\n"
                  "3- Bubble Sort\n"
                  "4- Shell Sort\n"
                  "5- Merge Sort\n"
                  "6- Quick Sort\n";
            cin>>SortType;
            Choosen_sort(SortType,"name",arr,choice);
            break;
        case 2:
            choice = 0;
            cout<<"Sort by: 1 - Insertion Sort\n"
                  "2- Selection Sort\n"
                  "3- Bubble Sort\n"
                  "4- Shell Sort\n"
                  "5- Merge Sort\n"
                  "6- Quick Sort\n";
            cin>>SortType;
            Choosen_sort(SortType,"gpa",arr,choice);
            break;
        default:
            cout<<"Wrong input\n";
            sort_students(arr);
    }
}
#endif //ASSIGNMENT_DATA_STRUCTURES_SORT_H
