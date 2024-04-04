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
    int maxDigits = this->maxDigits(maxValue);

    std::vector<int> output(vec.size(), 0);

    for (int place = 0; place < maxDigits; place++) {
        std::vector<int> count(base, 0);

        for (int i = 0; i < vec.size(); i++) {
            count[extractDigit(vec[i], place)]++;
        }

        for (int i = 1; i < base; i++) {
            count[i] += count[i - 1];
        }

        for (int i = vec.size() - 1; i >= 0; i--) {
            output[count[extractDigit(vec[i], place)] - 1] = vec[i];
            count[extractDigit(vec[i], place)]--;
        }

        vec = output;
    }
}