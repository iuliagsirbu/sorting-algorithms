#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H

#include "include/SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {
public:
    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_MERGESORT_H
