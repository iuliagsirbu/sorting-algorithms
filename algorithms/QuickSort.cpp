#include "QuickSort.h"

int QuickSort::median(std::vector<int> &vec, int p, int r) {
    int mid = p + (r - p) / 2;
    if (vec[mid] < vec[p])
        std::swap(vec[mid], vec[p]);
    if (vec[r] < vec[p])
        std::swap(vec[r], vec[p]);
    if (vec[r] < vec[mid])
        std::swap(vec[r], vec[mid]);
    return mid;
}

int QuickSort::partition(std::vector<int> &vec, int p, int r) {
    int index = median(vec, p, r);
    std::swap(vec[index], vec[r]);
    int pivot = vec[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[r]);
    return i + 1;
}

void QuickSort::quicksort(std::vector<int> &vec, int p, int r) {
    if (p < r) {
        int q = partition(vec, p, r);
        quicksort(vec, p, q - 1);
        quicksort(vec, q + 1, r);
    }
}

void QuickSort::sort(std::vector<int> &vec) {
    quicksort(vec, 0, vec.size() - 1);
}
