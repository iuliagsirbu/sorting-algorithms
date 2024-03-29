#include "HeapSort.h"

void HeapSort::sort(std::vector<int> &vec) {
    Heap heap(vec);
    heap.BUILD_MAX_HEAP();
    for (int i = vec.size() - 1; i >= 1; i--) {
        std::swap(heap.array[0], heap.array[i]);
        heap.heapSize--;
        heap.MAX_HEAPIFY(0);
    }
    vec = heap.array;
}

int HeapSort::Heap::PARENT(int i) {
    return (i - 1) / 2;
}

int HeapSort::Heap::LEFT(int i) {
    return (2 * i + 1);
}

int HeapSort::Heap::RIGHT(int i) {
    return (2 * i + 2);
}

void HeapSort::Heap::MAX_HEAPIFY(int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if (l < heapSize && array[l] > array[i])
        largest = l;
    else largest = i;

    if (r < heapSize && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        std::swap(array[i], array[largest]);
        MAX_HEAPIFY(largest);
    }
}

HeapSort::Heap::Heap(const std::vector<int> &input) : array(input), heapSize(input.size()) {}

void HeapSort::Heap::BUILD_MAX_HEAP() {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        MAX_HEAPIFY(i);
    }
}
