#include <cassert>
#include <vector>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int DifferenceMinMax(const std::vector<int>& a) {
    REQUIRE(!a.empty()); // Precondition: array must not be empty

    int minVal = a[0];
    int maxVal = a[0];

    for (size_t i = 1; i < a.size(); ++i) {
        // Loop invariants
        assert(1 <= i && i <= a.size());
        assert(minVal <= maxVal);
        for (size_t k = 0; k < i; ++k) {
            assert(minVal <= a[k] && a[k] <= maxVal);
        }
        // These invariants are implicitly maintained by the logic below
        // and thus do not need explicit checks in C++

        if (a[i] < minVal) {
            minVal = a[i];
        } else if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }

    int diff = maxVal - minVal;
    ENSURE(diff == *std::max_element(a.begin(), a.end()) - *std::min_element(a.begin(), a.end())); // Postcondition
    return diff;
}