#ifndef SORTING_ALGORITHMS_SHELLSORT_H
#define SORTING_ALGORITHMS_SHELLSORT_H

#include "include/SortingAlgorithm.h"

class ShellSort : public SortingAlgorithm {
public:
    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_SHELLSORT_H
