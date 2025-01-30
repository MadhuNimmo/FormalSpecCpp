#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int LastDigit(unsigned int n) {
    // Precondition: n must be non-negative (always true for unsigned int)
    REQUIRE(n >= 0);

    int d = n % 10;

    // Postconditions
    ENSURE(0 <= d && d < 10);
    ENSURE(n % 10 == d);

    return d;
}