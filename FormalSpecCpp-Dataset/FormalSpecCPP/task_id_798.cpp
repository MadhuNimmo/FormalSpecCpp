#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to compute the sum of elements up to the nth index
int sumTo(const std::vector<int>& a, size_t n) {
    REQUIRE(n <= a.size()); // Precondition

    if (n == 0) {
        return 0;
    } else {
        return sumTo(a, n - 1) + a[n - 1];
    }
}

// Method to compute the sum of all elements in the array
int ArraySum(const std::vector<int>& a) {
    int result = 0;
    size_t length = a.size();

    for (size_t i = 0; i < length; ++i) {
        assert(0 <= i && i <= length); // Loop invariant
        assert(result == sumTo(a, i)); // Loop invariant

        result += a[i];
    }

    ENSURE(result == sumTo(a, length)); // Postcondition
    return result;
}