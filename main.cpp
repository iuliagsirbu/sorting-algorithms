#include <iostream>
#include <vector>
#include "include/SortingAlgorithm.h"
#include "include/CountingSort.h"

void printSolution(const std::vector<int> &vec) {
    for (int val: vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> vec = {6, 5, 4, 3, 2, 1};
    SortingAlgorithm *sorter = new CountingSort();

    sorter->sort(vec);
    printSolution(vec);

    return 0;
}
