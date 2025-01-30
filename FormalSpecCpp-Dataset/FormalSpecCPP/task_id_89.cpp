#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int ClosestSmaller(int n) {
    // Precondition: n must be greater than 0
    REQUIRE(n > 0);

    // Calculation to find the closest smaller integer
    int m = n - 1;

    // Postcondition: m + 1 must be equal to n
    ENSURE(m + 1 == n);

    return m;
}