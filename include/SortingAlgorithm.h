#ifndef SORTING_ALGORITHMS_SORTINGALGORITHM_H
#define SORTING_ALGORITHMS_SORTINGALGORITHM_H

#include <iostream>
#include <vector>

class SortingAlgorithm {
public:
    virtual void sort(std::vector<int> &vec) = 0;
};


#endif //SORTING_ALGORITHMS_SORTINGALGORITHM_H
