#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool AllElementsEqual(const std::vector<int>& a, int n) {
    // Preconditions
    REQUIRE(!a.empty()); // This replaces the Dafny precondition that a != null and implicitly checks for non-empty array.

    bool result = true;
    size_t length = a.size(); // Using size_t for non-negative array size.

    for (size_t i = 0; i < length; ++i) {
        // Loop invariants
        assert(i <= length); // Ensures loop does not exceed array bounds.
        // The second invariant is implicitly maintained by the logic of the loop and break condition.

        if (a[i] != n) {
            result = false;
            break;
        }
    }

    // Postconditions
    if (result) {
        for (size_t i = 0; i < length; ++i) {
            ENSURE(a[i] == n); // Ensures all elements are equal to n if result is true.
        }
    } else {
        bool exists_not_equal = false;
        for (size_t i = 0; i < length; ++i) {
            if (a[i] != n) {
                exists_not_equal = true;
                break;
            }
        }
        ENSURE(exists_not_equal); // Ensures there is at least one element not equal to n if result is false.
    }

    return result;
}