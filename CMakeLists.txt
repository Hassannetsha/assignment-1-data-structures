cmake_minimum_required(VERSION 3.28)
project(assignment_data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        main.cpp
        part2/linkedQueue.h
        part2/Array_Based_Queue.cpp
        Student.cpp
        Student.h
        SORTING/insertion_sort.h
        SORTING/quick_sort.h
        SORTING/selection_sort.h
        part2/CircularLinkedList.cpp
        SORTING/MergeSort.hpp
        SORTING/ShellSort.hpp
        SORTING/Bubble_sort.hpp
)
