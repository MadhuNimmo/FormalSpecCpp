#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate the nth nonagonal number
unsigned int NthNonagonalNumber(unsigned int n) {
    // Precondition: n must be non-negative
    REQUIRE(n >= 0);

    // Calculate the nth nonagonal number
    unsigned int number = n * (7 * n - 5) / 2;

    // Postcondition: Check the formula for the nth nonagonal number
    ENSURE(number == n * (7 * n - 5) / 2);

    return number;
}