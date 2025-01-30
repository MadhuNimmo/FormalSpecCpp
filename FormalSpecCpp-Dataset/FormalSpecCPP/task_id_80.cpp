#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int TetrahedralNumber(unsigned int n) {
    // Precondition: n must be non-negative (implicitly true since n is unsigned)
    REQUIRE(n >= 0);

    // Calculate the tetrahedral number
    unsigned long long t = n * (n + 1) * (n + 2) / 6;

    // Postcondition: t should be equal to n * (n + 1) * (n + 2) / 6
    ENSURE(t == n * (n + 1) * (n + 2) / 6);

    return static_cast<int>(t);
}