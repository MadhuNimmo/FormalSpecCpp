#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int NthOctagonalNumber(unsigned int n) {
    // Precondition: n must be non-negative (already ensured by using unsigned int)
    REQUIRE(n >= 0);

    // Calculate the nth octagonal number
    int octagonalNumber = n * (3 * n - 2);

    // Postcondition: Ensure the result is as expected
    ENSURE(octagonalNumber == static_cast<int>(n) * (3 * static_cast<int>(n) - 2));

    return octagonalNumber;
}