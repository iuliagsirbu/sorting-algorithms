#ifndef SORTING_ALGORITHMS_COUNTINGSORT_H
#define SORTING_ALGORITHMS_COUNTINGSORT_H

#include "SortingAlgorithm.h"
#include <algorithm>

class CountingSort : public SortingAlgorithm {
    std::vector<int> frequency;
    std::vector<int> sorted;
public:
    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_COUNTINGSORT_H
