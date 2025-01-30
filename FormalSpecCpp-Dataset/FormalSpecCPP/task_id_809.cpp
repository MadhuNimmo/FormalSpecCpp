#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsSmaller(const std::vector<int>& a, const std::vector<int>& b) {
    // Precondition: a and b must be of the same size
    REQUIRE(a.size() == b.size());

    bool result = true;
    size_t n = a.size(); // Using size_t for non-negative values, as sizes cannot be negative

    for (size_t i = 0; i < n; ++i) {
        // Loop invariants
        assert(0 <= i && i <= n); // Ensures i is within the valid range
        // Ensures result is true if and only if all previous elements of a are greater than b
        assert(result == [&]() {
            for (size_t k = 0; k < i; ++k) {
                if (!(a[k] > b[k])) return false;
            }
            return true;
        }());
        // Ensures result is false if there exists any previous element of a that is not greater than b
        assert(!result == [&]() {
            for (size_t k = 0; k < i; ++k) {
                if (a[k] <= b[k]) return true;
            }
            return false;
        }());

        if (a[i] <= b[i]) {
            result = false;
            break;
        }
    }

    // Postconditions
    ENSURE(result == [&]() {
        for (size_t i = 0; i < n; ++i) {
            if (!(a[i] > b[i])) return false;
        }
        return true;
    }());
    ENSURE(!result == [&]() {
        for (size_t i = 0; i < n; ++i) {
            if (a[i] <= b[i]) return true;
        }
        return false;
    }());

    return result;
}