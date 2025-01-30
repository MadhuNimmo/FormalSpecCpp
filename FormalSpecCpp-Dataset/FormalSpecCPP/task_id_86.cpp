#include <cassert>
#include <cstddef>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int CenteredHexagonalNumber(size_t n) {
    // Precondition: n must be non-negative (size_t is always non-negative)
    REQUIRE(n >= 0);

    // Calculation to find the centered hexagonal number
    unsigned int result = 3 * n * (n - 1) + 1;

    // Postcondition: result must be equal to 3 * n * (n - 1) + 1
    ENSURE(result == 3 * n * (n - 1) + 1);

    return result;
}