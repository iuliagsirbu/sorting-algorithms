#include <iostream>
#include <vector>
#include <cassert>
#include "SortingAlgorithm.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include "QuickSort.h"

void printSolution(const std::vector<int> &vec) {
    for (int val: vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> vec = {6, 5, 4, 3, 2, 1};
    std::vector<int> verify = vec;
//    SortingAlgorithm *sorter = new CountingSort();
//
//    sorter->sort(vec);
////    printSolution(vec);
//    std::sort(verify.begin(), verify.end());
//    assert(vec == verify && "Counting Sort");

//    SortingAlgorithm *sorter = new HeapSort();
//    SortingAlgorithm *sorter = new RadixSort(65536); // 2^16 = 65536
    SortingAlgorithm *sorter = new QuickSort();
    sorter->sort(vec);
    printSolution(vec);

    return 0;
}
