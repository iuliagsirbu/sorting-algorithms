#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm {
private:
    static int median(std::vector<int> &vec, int p, int r);

    static int partition(std::vector<int> &vec, int p, int r);

    void quicksort(std::vector<int> &vec, int p, int r);

public:
    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_QUICKSORT_H
