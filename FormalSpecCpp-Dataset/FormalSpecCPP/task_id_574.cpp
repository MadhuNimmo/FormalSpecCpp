#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

long CylinderSurfaceArea(double radius, double height) {
    // Preconditions
    REQUIRE(radius > 0.0);
    REQUIRE(height > 0.0);

    // Calculation: Surface area of a cylinder is 2πr(r + h)
    long area = 2.0 * M_PI * radius * (radius + height);

    // Postconditions: Ensure that the calculated area matches the expected formula
    ENSURE(area == static_cast<long>(2.0 * M_PI * radius * (radius + height)));

    return area;
}
