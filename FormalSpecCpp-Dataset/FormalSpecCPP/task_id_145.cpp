#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int MaxDifference(const std::vector<int>& a) {
    // Precondition: the array must have more than one element
    REQUIRE(a.size() > 1);

    int minVal = a[0];
    int maxVal = a[0];

    // Loop through the array starting from the second element
    for (size_t i = 1; i < a.size(); ++i) {
        // Loop invariants
        assert(i >= 1 && i <= a.size()); // Ensures loop bounds are correct
        assert(minVal <= maxVal); // Ensures minVal is always less than or equal to maxVal

        if (a[i] < minVal) {
            minVal = a[i];
        } else if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }

    int diff = maxVal - minVal;

    // Postcondition: the difference should be the maximum difference in the array
    ENSURE([&]() {
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a.size(); ++j) {
                if (a[i] - a[j] > diff) {
                    return false;
                }
            }
        }
        return true;
    }());

    return diff;
}