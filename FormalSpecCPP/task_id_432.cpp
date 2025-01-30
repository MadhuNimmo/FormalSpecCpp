#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double MedianLength(unsigned int a, unsigned int b) {
    // Preconditions
    REQUIRE(a > 0 && b > 0);

    // Calculation of the median
    double median = (static_cast<double>(a) + static_cast<double>(b)) / 2.0;

    // Postconditions
    ENSURE(median == (static_cast<double>(a) + static_cast<double>(b)) / 2.0);

    return median;
}
