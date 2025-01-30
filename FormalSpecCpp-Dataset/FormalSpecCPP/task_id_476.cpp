#include <cassert>
#include <vector>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int SumMinMax(const std::vector<int>& a) {
    REQUIRE(!a.empty()); // precondition: array must not be empty

    int minVal = a[0];
    int maxVal = a[0];

    for (size_t i = 1; i < a.size(); ++i) {
        // Loop invariants
        assert(1 <= i && i <= a.size()); // invariant: i is within the valid range
        assert(minVal <= maxVal); // invariant: minVal is always less than or equal to maxVal

        if (a[i] < minVal) {
            minVal = a[i];
        } else if (a[i] > maxVal) {
            maxVal = a[i];
        }

        // Asserting the loop invariant that the current min and max are correct
        assert(*std::min_element(a.begin(), a.begin() + i + 1) == minVal);
        assert(*std::max_element(a.begin(), a.begin() + i + 1) == maxVal);
    }

    int sum = minVal + maxVal;
    ENSURE(sum == *std::max_element(a.begin(), a.end()) + *std::min_element(a.begin(), a.end())); // postcondition

    return sum;
}