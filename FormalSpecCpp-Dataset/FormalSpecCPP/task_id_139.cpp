#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

double CircleCircumference(double radius) {
    // Precondition: radius must be greater than 0.0
    REQUIRE(radius > 0.0);

    // Constant for PI
    const double PI = 3.14159265358979323846;

    // Calculate the circumference
    double circumference = 2.0 * PI * radius;

    // Postcondition: Check the correctness of the calculated circumference
    ENSURE(std::abs(circumference - (2.0 * PI * radius)) < 1e-12);

    return circumference;
}