#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double SphereSurfaceArea(double radius) {
    // Precondition: radius must be greater than 0.0
    REQUIRE(radius > 0.0);

    const double pi = 3.14159265358979323846;
    double area = 4.0 * pi * radius * radius;

    // Postcondition: area must be equal to 4 * pi * radius^2
    ENSURE(area == 4.0 * pi * radius * radius);

    return area;
}