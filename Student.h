#ifndef ASSIGNMENT_DATA_STRUCTURES_STUDENT_H
#define ASSIGNMENT_DATA_STRUCTURES_STUDENT_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "SORTING/insertion_sort.h"
#include <chrono>
#include "SORTING/insertion_sort.h"
#include "SORTING/selection_sort.h"
#include "SORTING/quick_sort.h"
#include "SORTING/MergeSort.hpp"
#include "SORTING/Bubble_sort.hpp"
#include "SORTING/ShellSort.hpp"
using namespace std;
class Student {
private:
    string id;
    string name;
    int gpa{};
public:
    Student() = default;
    Student(const string &id, const string &name, const int &gpa);
    friend vector<Student> open_file();
    bool operator<(const Student &student);
    bool operator<=(const Student &student) const;
    bool operator>(const Student &student);
    bool operator>=(const Student &student);
    friend ostream &operator<<(ostream &os, const Student &student);
    template<typename t>
    friend void print(vector<t> students);
private:
    bool sortByGpa;
};

#endif //ASSIGNMENT_DATA_STRUCTURES_STUDENT_H
