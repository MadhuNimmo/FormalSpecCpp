#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

#define EPSILON 1e-2 

double CylinderVolume(double radius, double height) {
    // Preconditions
    REQUIRE(radius > 0.0);
    REQUIRE(height > 0.0);

    // Calculation
    double volume = M_PI * radius * radius * height;

    // Postcondition
    ENSURE(std::abs(volume - (M_PI * radius * radius * height)) < EPSILON);

    return volume;
}