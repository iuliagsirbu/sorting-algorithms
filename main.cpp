#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <typeinfo>

/* SORTING ALGORITHMS HEADERS */
#include "SortingAlgorithm.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include "QuickSort.h"

/* EXCEPTIONS */
#include "SortingException.h"

/* INPUT OUTPUT */
std::ifstream fin("data.in");
std::ofstream fout("data.out");
std::ofstream logFile("errors.log", std::ios::app);

bool test_sort(const std::vector<int> &v) {
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i - 1] > v[i])
            return false;
    }
    return true;
}

void run_tests() {
    std::vector<int> ns = {1000, 100000, 1000000};
    std::vector<int> max_values = {1000, 1000000, 100000000};

    std::vector<SortingAlgorithm *> sorters = {
            new CountingSort(), new MergeSort(), new ShellSort(), new HeapSort(), new RadixSort(10),
            new RadixSort(65536),
            new QuickSort()
    };

    for (auto n: ns) {
        for (auto max: max_values) {
            fout << "\nN: " << n << " MAX: " << max << "\n";
            std::vector<int> numbers(n);

            std::generate(numbers.begin(), numbers.end(), [max]() { return rand() % max; });

            for (auto sorter: sorters) {
                auto numbers_copy = numbers;

                try {
                    auto start = std::chrono::high_resolution_clock::now();
                    sorter->sort(numbers_copy);
                    auto end = std::chrono::high_resolution_clock::now();

                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

                    fout << typeid(*sorter).name() << ": " << duration << " ms, ";

                    if (test_sort(numbers_copy)) {
                        fout << "Passed";
                    } else {
                        fout << "Failed";
                    }
                } catch (const SortingException &e) {
                    logFile << "Error during sorting with " << typeid(*sorter).name() << ": " << e.what()
                            << ", at test with " << n << " " << max << std::endl;
                    fout << "Error: " << e.what();
                }
                fout << "\n";
            }
        }
    }

    for (auto sorter: sorters) {
        delete sorter;
    }
}

int main() {
    try {
        run_tests();
    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        logFile << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
