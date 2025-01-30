#include <vector>
#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate power of a base to an exponent
int Power(int base, unsigned int exponent) {
    REQUIRE(exponent >= 0); // Precondition

    if (exponent == 0) {
        return 1;
    } else {
        return base * Power(base, exponent - 1);
    }
}

// Method to apply the Power function to each element of a list
std::vector<int> PowerOfListElements(const std::vector<int>& l, unsigned int n) {
    REQUIRE(n >= 0); // Precondition

    std::vector<int> result;
    result.reserve(l.size()); // Reserve space to avoid reallocations

    for (size_t i = 0; i < l.size(); ++i) {
        // Loop invariants
        assert(i <= l.size()); // Ensures i does not exceed list size
        assert(result.size() == i); // Ensures result size matches the current index

        // Check the power calculation for each element added so far
        for (size_t k = 0; k < i; ++k) {
            assert(result[k] == Power(l[k], n));
        }

        result.push_back(Power(l[i], n));
    }

    // Postconditions
    ENSURE(result.size() == l.size()); // Ensure the result size matches input list size
    for (size_t i = 0; i < l.size(); ++i) {
        ENSURE(result[i] == Power(l[i], n)); // Ensure each element is correctly powered
    }

    return result;
}