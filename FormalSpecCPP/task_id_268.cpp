#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate the star number for a given n
unsigned int StarNumber(unsigned int n) {
    // Precondition: n must be non-negative
    REQUIRE(n >= 0);

    // Calculate the star number
    unsigned int star = 6 * n * (n - 1) + 1;

    // Postcondition: star should be equal to 6 * n * (n - 1) + 1
    ENSURE(star == 6 * n * (n - 1) + 1);

    return star;
}