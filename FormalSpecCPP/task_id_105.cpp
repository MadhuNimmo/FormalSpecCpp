#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to count the number of true values in a subarray
int countTo(const std::vector<bool>& a, size_t n) {
    REQUIRE(n <= a.size()); // Precondition

    if (n == 0) {
        return 0;
    } else {
        return countTo(a, n - 1) + (a[n - 1] ? 1 : 0);
    }
}

// Method to count the number of true values in the entire array
int CountTrue(const std::vector<bool>& a) {
    REQUIRE(!a.empty()); // Precondition

    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        assert(0 <= i && i <= a.size()); // Loop invariant: index bounds
        assert(result == countTo(a, i)); // Loop invariant: correctness of result so far

        if (a[i]) {
            result += 1;
        }
    }

    ENSURE(result == countTo(a, a.size())); // Postcondition
    return result;
}