#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H

#include "include/SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {
private:
    static void merge(std::vector<int> &vec, int p, int q, int r);

    void mergesort(std::vector<int> &vec, int p, int r);

public:
    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_MERGESORT_H
