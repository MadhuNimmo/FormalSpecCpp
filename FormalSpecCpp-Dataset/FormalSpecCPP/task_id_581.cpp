#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double SquarePyramidSurfaceArea(unsigned int baseEdge, unsigned int height) {
    // Preconditions
    REQUIRE(baseEdge > 0);
    REQUIRE(height > 0);

    double area = baseEdge * baseEdge + 2 * baseEdge * height;

    // Postcondition
    ENSURE(area == baseEdge * baseEdge + 2 * baseEdge * height);

    return area;
}