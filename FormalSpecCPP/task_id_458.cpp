#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int RectangleArea(unsigned int length, unsigned int width) {
    // Preconditions
    REQUIRE(length > 0);
    REQUIRE(width > 0);

    unsigned int area = length * width;

    // Postcondition
    ENSURE(area == length * width);

    return area;
}