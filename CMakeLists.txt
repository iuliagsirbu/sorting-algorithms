cmake_minimum_required(VERSION 3.27)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorting_algorithms main.cpp
        algorithms/SortingAlgorithm.cpp
        include/SortingAlgorithm.h
        algorithms/MergeSort.cpp
        include/MergeSort.h
        algorithms/CountingSort.cpp
        include/CountingSort.h
        algorithms/ShellSort.cpp
        include/ShellSort.h
        algorithms/HeapSort.cpp
        include/HeapSort.h
        algorithms/RadixSort.cpp
        include/RadixSort.h
        algorithms/QuickSort.cpp
        include/QuickSort.h
)

include_directories(.)
include_directories(include)