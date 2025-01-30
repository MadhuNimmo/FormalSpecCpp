#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int NthHexagonalNumber(unsigned int n) {
    // Precondition: n must be non-negative (already ensured by using unsigned int)
    REQUIRE(n >= 0);

    // Calculate the nth hexagonal number
    unsigned int hexNum = n * ((2 * n) - 1);

    // Postcondition: Ensure the result is correct
    ENSURE(hexNum == n * ((2 * n) - 1));

    return hexNum;
}