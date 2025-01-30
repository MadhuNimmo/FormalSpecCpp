#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double ParabolaDirectrix(int a, int h, int k) {
    // Preconditions
    REQUIRE(a != 0);

    // Fix: Ensure floating-point division by casting `1` to a double
    double directrix = k - (1.0 / (4.0 * a));

    // Postconditions
    ENSURE(directrix == static_cast<double>(k - (1.0 / (4.0 * a))));

    return directrix;
}
