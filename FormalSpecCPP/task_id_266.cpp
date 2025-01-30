#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int LateralSurfaceArea(unsigned int size) {
    // Precondition: size must be greater than 0
    REQUIRE(size > 0);

    // Calculation of the lateral surface area
    unsigned int area = 4 * size * size;

    // Postcondition: area must be equal to 4 * size * size
    ENSURE(area == 4 * size * size);

    return area;
}