#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double ConeVolume(double radius, double height) {
    // Preconditions
    REQUIRE(radius > 0.0);
    REQUIRE(height > 0.0);

    // Calculation
    double volume = (1.0 / 3.0) * 3.14159265358979323846 * radius * radius * height;

    // Postconditions
    ENSURE(std::abs(volume - ((1.0 / 3.0) * 3.14159265358979323846 * radius * radius * height)) < 1e-12);

    return volume;
}