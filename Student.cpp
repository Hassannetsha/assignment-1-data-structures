#include "Student.h"

using namespace std;

Student::Student(const string &id, const string &name, const int &gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
}

bool Student::operator<(const Student &student) {
    return (this->name < student.name);
}

ostream &operator<<(ostream &os, const Student &student) {
    cout << "ID: " << setw(10) << setfill(' ') << student.id << "    Name: " << setw(15) << setfill(' ') << student.name
         << "    GPA: " << setw(4) << setfill(' ') << student.gpa << '\n';
    return os;
}

string Student::getName() {
    return name;
}

int Student::getGpa() const {
    return gpa;
}

string Student::getId() {
    return id;
}

bool Student::operator<=(const Student &student) {
    return (this->name <= student.name);
}

bool Student::operator>(const Student &student) {
    return (this->name > student.name);
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
                auto Gpa = (int)stod(gpa_str);
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
void print(t students) {
    for (auto const &i: students) {
        cout<<i;
    }
}

