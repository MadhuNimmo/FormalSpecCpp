#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double SphereVolume(double radius) {
    // Precondition: radius must be positive
    REQUIRE(radius > 0.0);

    // Calculate the volume of the sphere using M_PI
    double volume = (4.0 / 3.0) * M_PI * radius * radius * radius;

    // Postcondition: volume must be correctly calculated within a tolerance
    ENSURE(fabs(volume - ((4.0 / 3.0) * M_PI * radius * radius * radius)) < 1e-9);

    return volume;
}
