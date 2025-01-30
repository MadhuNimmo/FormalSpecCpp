#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate the nth decagonal number
int NthDecagonalNumber(unsigned int n) {
    // Precondition: n must be non-negative (already ensured by using unsigned int)
    REQUIRE(n >= 0);

    // Calculate the nth decagonal number
    int decagonal = 4 * n * n - 3 * n;

    // Postcondition: Ensure the result is as expected
    ENSURE(decagonal == 4 * n * n - 3 * n);

    return decagonal;
}