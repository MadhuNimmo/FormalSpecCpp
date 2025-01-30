#include <vector>
#include <algorithm>


int SumMinMax(const std::vector<int>& a) {

    int minVal = a[0];
    int maxVal = a[0];

    for (size_t i = 1; i < a.size(); ++i) {

        if (a[i] < minVal) {
            minVal = a[i];
        } else if (a[i] > maxVal) {
            maxVal = a[i];
        }

    }

    int sum = minVal + maxVal;

    return sum;
}
