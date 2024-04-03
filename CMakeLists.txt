cmake_minimum_required(VERSION 3.27)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorting_algorithms main.cpp
        SortingAlgorithm.cpp
        include/SortingAlgorithm.h
        MergeSort.cpp
        include/MergeSort.h
        CountingSort.cpp
        include/CountingSort.h
        ShellSort.cpp
        include/ShellSort.h
        HeapSort.cpp
        include/HeapSort.h
        RadixSort.cpp
        include/RadixSort.h
        QuickSort.cpp
        include/QuickSort.h
)

include_directories(.)
include_directories(include)