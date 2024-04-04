#include "CountingSort.h"
#include "SortingException.h"

void CountingSort::sort(std::vector<int> &vec) {
    if (vec.empty())
        return;

    int maxValue = *std::max_element(vec.begin(), vec.end());

    if (maxValue > 1000000) {
        throw SortingException("CountingSort -> Memory issues");
    }

    frequency.resize(maxValue + 1, 0);
    std::vector<int> sorted;

    for (int val: vec) {
        frequency[val]++;
    }

    for (int i = 0; i <= maxValue; i++) {
        for (int j = 0; j < frequency[i]; j++) {
            sorted.push_back(i);
        }
    }

    vec = sorted;
}