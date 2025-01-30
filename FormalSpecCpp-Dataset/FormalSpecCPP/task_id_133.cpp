#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to sum negative numbers up to index n in the array
int sumNegativesTo(const std::vector<int>& a, size_t n) {
    REQUIRE(n <= a.size()); // Precondition

    if (n == 0) {
        return 0;
    } else {
        int lastElement = a[n - 1];
        int sum = sumNegativesTo(a, n - 1);
        if (lastElement < 0) {
            return sum + lastElement;
        } else {
            return sum;
        }
    }
}

// Method to compute the sum of all negative numbers in the array
int SumOfNegatives(const std::vector<int>& a) {
    int result = 0;
    size_t length = a.size();
    REQUIRE(length == a.size()); // Precondition

    for (size_t i = 0; i < length; ++i) {
        assert(0 <= i && i <= length); // Loop invariant
        if (a[i] < 0) {
            result += a[i];
        }
        assert(result == sumNegativesTo(a, i + 1)); // Loop invariant
    }

    ENSURE(result == sumNegativesTo(a, length)); // Postcondition
    return result;
}