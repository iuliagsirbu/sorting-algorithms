#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H

#include "SortingAlgorithm.h"

class HeapSort : public SortingAlgorithm {
private:
    class Heap {
    private:
        std::vector<int> array;
        int heapSize;

        static int PARENT(int i);

        static int LEFT(int i);

        static int RIGHT(int i);

        void MAX_HEAPIFY(int i);

    public:
        explicit Heap(const std::vector<int> &input);

        void BUILD_MAX_HEAP();

        friend class HeapSort;
    };

public:
    void sort(std::vector<int> &vec) override;
};


#endif //SORTING_ALGORITHMS_HEAPSORT_H
