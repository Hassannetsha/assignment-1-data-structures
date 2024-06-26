#include "Student.h"

using namespace std;

Student::Student(const string &id, const string &name, const int &gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    sortByGpa = true;
}

/*checks sort if sort by name or sort by GPA*/
bool Student::operator<(const Student &student) {
    if (!sortByGpa) {
        return (this->name < student.name);
    } else {
        return this->gpa < student.gpa;
    }
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.name << '\n' << student.id << '\n' << student.gpa;
    return os;
}

bool Student::operator<=(const Student &student) const {
    if (sortByGpa) {
        return (this->gpa <= student.gpa);
    } else {
        return (this->name <= student.name);
    }
}

bool Student::operator>(const Student &student) {
    if (!sortByGpa) {
        return (this->name > student.name);
    } else {
        return (this->gpa > student.gpa);
    }
}

bool Student::operator>=(const Student &student) {
    if (!sortByGpa) {
        return (this->name >= student.name);
    } else {
        return (this->gpa >= student.gpa);
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

// prints every sort in the files
template<typename t>
void print(vector<t> students) {
    vector<t> copy = students;
    int comparisons = 0;
    //sort by Gpa
    //insertion sort
    ofstream outFile1("SortedByGPA.txt");
    auto startTime = chrono::steady_clock::now();
    insertion_sort(students, students.size(), comparisons);
    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile1 << "Algorithm: Insertion Sort\n";
    outFile1 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile1 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile1 << j << '\n';
    }
    outFile1 << '\n' << '\n';
    students = copy;
    comparisons = 0;
    //selection sort
    startTime = chrono::steady_clock::now();
    selection(students, students.size(),comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile1 << "Algorithm: Selection Sort\n";
    outFile1 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile1 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile1 << j << '\n';
    }
    outFile1 << '\n' << '\n';
    students = copy;
    comparisons = 0;
    // quick sort
    startTime = chrono::steady_clock::now();
    quick_sort(students, 0, students.size(),comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile1 << "Algorithm: Quick Sort\n";
    outFile1 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile1 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile1 << j << '\n';
    }
    outFile1 << '\n' << '\n';
    students = copy;
    comparisons = 0;
    //shell sort
    startTime = chrono::steady_clock::now();
    shellSort(students, students.size(),comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile1 << "Algorithm: Shell Sort\n";
    outFile1 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile1 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile1 << j << '\n';
    }
    outFile1 << '\n' << '\n';
    //Bubble sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    BubbleSort(students, students.size(), comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile1 << "Algorithm: Bubble Sort\n";
    outFile1 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile1 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile1 << j << '\n';
    }
    outFile1 << '\n' << '\n';
    //Merge sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    mergeSort(students, 0, students.size() - 1,comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile1 << "Algorithm: Merge Sort\n";
    outFile1 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile1 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile1 << j << '\n';
    }
    outFile1.close();
    //sort by name
    //insertion sort
    ofstream outFile2("SortedByName.txt");
    for (auto &j: students) {
        j.sortByGpa = false;
    }
    copy = students;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    insertion_sort(students, students.size(), comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile2 << "Algorithm: Insertion Sort\n";
    outFile2 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile2 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile2 << j << '\n';
    }
    outFile2 << '\n' << '\n';
    //selection sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    selection(students, students.size(),comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile2 << "Algorithm: Selection Sort\n";
    outFile2 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile2 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile2 << j << '\n';
    }
    outFile2 << '\n' << '\n';
    //Quick sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    quick_sort(students, 0, students.size(),comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile2 << "Algorithm: Quick Sort\n";
    outFile2 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile2 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile2 << j << '\n';
    }
    outFile2 << '\n' << '\n';
    //Shell sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    shellSort(students, students.size(),comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile2 << "Algorithm: Shell Sort\n";
    outFile2 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile2 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile2 << j << '\n';
    }
    outFile2 << '\n' << '\n';
    //Bubble sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    BubbleSort(students, students.size(), comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile2 << "Algorithm: Bubble Sort\n";
    outFile2 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile2 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile2 << j << '\n';
    }
    outFile2 << '\n' << '\n';
    //Merge sort
    students = copy;
    comparisons = 0;
    startTime = chrono::steady_clock::now();
    mergeSort(students, 0, students.size() - 1,comparisons);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    outFile2 << "Algorithm: Merge Sort\n";
    outFile2 << "Number of comparisons: " << comparisons << " comparisons\n";
    outFile2 << "Running Time:" << duration.count() << " nanoseconds" << "\n";
    for (auto const &j: students) {
        outFile2 << j << '\n';
    }
    outFile2.close();
}
