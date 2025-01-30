#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsSorted(const std::vector<int>& a) {
    // Precondition: the array must have at least one element
    REQUIRE(a.size() > 0);

    bool sorted = true;

    // Loop through the array to check if it is sorted
    for (size_t i = 0; i < a.size() - 1; ++i) {
        // Loop invariant: all elements up to the current point are sorted
        assert(sorted == [&]() {
            for (size_t k = 0; k < i; ++k) {
                for (size_t l = k + 1; l < i; ++l) {
                    if (a[k] > a[l]) return false;
                }
            }
            return true;
        }());

        // Loop invariant: if not sorted, there exists at least one pair (k, k+1) where a[k] > a[k+1]
        assert(!sorted == [&]() {
            for (size_t k = 0; k < i; ++k) {
                if (a[k] > a[k + 1]) return true;
            }
            return false;
        }());

        // Check if the current element is greater than the next element
        if (a[i] > a[i + 1]) {
            sorted = false;
            break;
        }
    }

    // Postcondition: the array is sorted if and only if all pairs (i, j) where i < j have a[i] <= a[j]
    ENSURE(sorted == [&]() {
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = i + 1; j < a.size(); ++j) {
                if (a[i] > a[j]) return false;
            }
        }
        return true;
    }());

    // Postcondition: if not sorted, there exists at least one pair (i, j) where i < j and a[i] > a[j]
    ENSURE(!sorted == [&]() {
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = i + 1; j < a.size(); ++j) {
                if (a[i] > a[j]) return true;
            }
        }
        return false;
    }());

    return sorted;
}