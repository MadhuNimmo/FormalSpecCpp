#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int PentagonPerimeter(unsigned int side) {
    // Precondition: side must be greater than 0
    REQUIRE(side > 0);

    unsigned int perimeter = 5 * side;

    // Postcondition: perimeter must be equal to 5 times side
    ENSURE(perimeter == 5 * side);

    return perimeter;
}