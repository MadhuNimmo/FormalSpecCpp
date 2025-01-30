#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int CubeSurfaceArea(unsigned int size) {
    // Precondition: size must be greater than 0
    REQUIRE(size > 0);

    // Calculate the surface area of the cube
    unsigned int area = 6 * size * size;

    // Postcondition: area must be equal to 6 * size * size
    ENSURE(area == 6 * size * size);

    return area;
}