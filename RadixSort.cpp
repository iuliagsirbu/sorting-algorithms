#include "RadixSort.h"
#include <cmath>
#include <algorithm>

int RadixSort::extractDigit(int number, int place) const {
    return (number / static_cast<int>(std::pow(base, place))) % base;
}

int RadixSort::maxDigits(int maxValue) const {
    int maxDigits = 0;
    while (maxValue > 0) {
        maxValue /= base;
        maxDigits++;
    }
    return maxDigits;
}

RadixSort::RadixSort(int base) : base(base) {}

void RadixSort::sort(std::vector<int> &vec) {
    if (vec.empty()) return;

    int maxValue = *std::max_element(vec.begin(), vec.end());
    int maxDigits = RadixSort::maxDigits(maxValue);

    for (int place = 0; place < maxDigits; place++) {
        std::vector<int> sorted(vec.size());

        for (int i = 0; i < vec.size(); i++) {
            sorted[i] = extractDigit(vec[i], place);
        }

        countingSort.sort(sorted);

        vec = sorted;
    }
}
