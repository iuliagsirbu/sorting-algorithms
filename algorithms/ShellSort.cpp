#include "ShellSort.h"

void ShellSort::sort(std::vector<int> &vec) {
    int N = vec.size();
    int h = 1;
    while (h < N / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < N; i++) {
            for (int j = i; j >= h && (vec[j] < vec[j - h]); j -= h) {
                std::swap(vec[j], vec[j - h]);
            }
        }
        h = h / 3;
    }
}