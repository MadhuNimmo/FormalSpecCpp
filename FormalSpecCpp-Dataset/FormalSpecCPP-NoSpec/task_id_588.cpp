#include <vector>
#include <algorithm>


int DifferenceMinMax(const std::vector<int>& a) {

    int minVal = a[0];
    int maxVal = a[0];

    for (size_t i = 1; i < a.size(); ++i) {
        // These invariants are implicitly maintained by the logic below
        // and thus do not need explicit checks in C++

        if (a[i] < minVal) {
            minVal = a[i];
        } else if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }

    int diff = maxVal - minVal;
    return diff;
}
