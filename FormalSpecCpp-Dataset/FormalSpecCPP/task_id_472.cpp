#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool ContainsConsecutiveNumbers(const std::vector<int>& a) {
    // Precondition: The array must have at least one element.
    REQUIRE(a.size() > 0);

    bool result = true;

    // Loop through the array to find consecutive numbers
    for (size_t i = 0; i < a.size() - 2; ++i) {  // Stop at a.size() - 2 to safely check a[i+2]
        // Loop invariant: 0 <= i <= a.size() - 3
        assert(0 <= i && i <= a.size() - 3);
        
        // Check if the current element and the next two form a consecutive sequence
        if (a[i] + 1 != a[i + 1]) {
            result = false;
            break;
        }
    }

    // Postcondition: result is true if and only if there exists some i such that a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]
    ENSURE(result == [&]() {
        for (size_t i = 0; i < a.size() - 2; ++i) {
            if (a[i] + 1 != a[i + 1]) {
                return false;
            }
        }
        return true;
    }());

    return result;
}