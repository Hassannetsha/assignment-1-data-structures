#include "Student.h"

using namespace std;

Student::Student(const string &id, const string &name, const int &gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    sortByGpa = true;
}

bool Student::operator<(const Student &student) {
    if (!sortByGpa) {
        return (this->name < student.name);
    }
    else {
        return this->gpa < student.gpa;
    }
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.name << '\n'<< student.id<< '\n'<< student.gpa;
    return os;
}

bool Student::operator<=(const Student &student) const {
    if(sortByGpa){
        return (this->gpa <= student.gpa);
    }
    else{
        return (this->name <= student.name);
    }
}
bool Student::operator>(const Student &student) {
    if(!sortByGpa){
        return (this->name > student.name);
    }
    else{
        return (this->gpa > student.gpa);
    }
}
vector<Student> open_file() {
    vector<Student> students;
    ifstream file("students.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            string Id, Name, gpa_str;
            Name = line;
            if (getline(file, Id) && getline(file, gpa_str)) {
                auto Gpa = (int) stod(gpa_str);
                students.emplace_back(Id, Name, Gpa);
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << "students.txt" << endl;
    }
    return students;
}

template<typename t>
void print(vector<t> students) {
    vector<t> copy = students;
    //sort by Gpa
    ofstream outFile1("SortedByGPA.txt");
    //insertion sort
    auto startTime = std::chrono::steady_clock::now();
    insertion_sort(students,students.size());
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    outFile1<<"Algorithm: Insertion Sort\n";
    outFile1<<"Running Time:"<<duration.count()<<" milliseconds"<<"\n";
    for (auto const &j:students) {
        outFile1<<j<<'\n';
    }
    students = copy;
    //selection sort
    startTime = std::chrono::steady_clock::now();
    selection(students,students.size());
    endTime = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    outFile1<<"Algorithm: Selection Sort\n";
    outFile1<<"Running Time:"<<duration.count()<<" milliseconds"<<"\n";
    for (auto const &j:students) {
        outFile1<<j<<'\n';
    }
    students = copy;
    // quick sort
    startTime = std::chrono::steady_clock::now();
    quick_sort(students,0,students.size());
    endTime = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    outFile1<<"Algorithm: Quick Sort\n";
    outFile1<<"Running Time:"<<duration.count()<<" milliseconds"<<"\n";
    for (auto const &j:students) {
        outFile1<<j<<'\n';
    }
    students = copy;
    outFile1.close();
    //sort by name
    //insertion sort
    ofstream outFile2("SortedByName.txt");
    for (auto &j: students) {
        j.sortByGpa = false;
    }
    copy = students;
    startTime = std::chrono::steady_clock::now();
    insertion_sort(students,students.size());
    endTime = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    outFile2<<"Algorithm: Insertion Sort\n";
    outFile2<<"Running Time:"<<duration.count()<<" milliseconds"<<"\n";
    for (auto const &j:students) {
        outFile2<<j<<'\n';
    }
    //selection sort
    students = copy;
    startTime = std::chrono::steady_clock::now();
    selection(students,students.size());
    endTime = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    outFile2<<"Algorithm: Selection Sort\n";
    outFile2<<"Running Time:"<<duration.count()<<" milliseconds"<<"\n";
    for (auto const &j:students) {
        outFile2<<j<<'\n';
    }
    //quick sort
    students = copy;
    quick_sort(students,0,students.size());
    endTime = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    outFile2<<"Algorithm: Quick Sort\n";
    outFile2<<"Running Time:"<<duration.count()<<" milliseconds"<<"\n";
    for (auto const &j:students) {
        outFile2<<j<<'\n';
    }
    students = copy;
    outFile2.close();
}
