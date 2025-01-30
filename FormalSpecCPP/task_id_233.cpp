#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

long double CylinderLateralSurfaceArea(double radius, double height) {
    // Preconditions
    REQUIRE(radius > 0.0);
    REQUIRE(height > 0.0);

    // Calculation
    long double area = 2.0 * (radius * height) * M_PI;

    // Postconditions
    ENSURE(std::abs(area - 2.0 * (radius * height) * M_PI) < 1e-6);

    return area;
}