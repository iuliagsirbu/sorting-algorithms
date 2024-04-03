#include "MergeSort.h"

void MergeSort::sort(std::vector<int> &vec) {
    mergesort(vec, 0, vec.size() - 1);
}

void MergeSort::merge(std::vector<int> &vec, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;

    std::vector<int> L(nL), R(nR);

    for (int i = 0; i < nL; i++) {
        L[i] = vec[p + i];
    }
    for (int j = 0; j < nR; j++) {
        R[j] = vec[q + j + 1];
    }

    int i = 0, j = 0, k = p;

    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        vec[k] = L[i];
        i++, k++;
    }

    while (j < nR) {
        vec[k] = R[j];
        j++, k++;
    }
}

void MergeSort::mergesort(std::vector<int> &vec, int p, int r) {
    if (p >= r)
        return;
    int q = (p + r) / 2;
    mergesort(vec, p, q);
    mergesort(vec, q + 1, r);
    merge(vec, p, q, r);
}
