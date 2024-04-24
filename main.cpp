#include "SORTING/Sort.h"
#include "Student.cpp"
using namespace std;
int main(){
    vector<Student> st;
    st = open_file();
    sort_students(st);
    print(st);
}