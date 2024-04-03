#ifndef SORTING_ALGORITHMS_RADIXSORT_H
#define SORTING_ALGORITHMS_RADIXSORT_H

#include "SortingAlgorithm.h"
#include "CountingSort.h"

class RadixSort : public SortingAlgorithm {
private:
    int base;

    CountingSort countingSort;

    int extractDigit(int number, int place) const;

    int maxDigits(int maxValue) const;

public:
    explicit RadixSort(int base);

    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_RADIXSORT_H
