#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate the perimeter of a square
unsigned int SquarePerimeter(unsigned int side) {
    // Precondition: side must be greater than 0
    REQUIRE(side > 0);

    // Calculate the perimeter
    unsigned int perimeter = 4 * side;

    // Postcondition: perimeter must be equal to 4 times the side
    ENSURE(perimeter == 4 * side);

    return perimeter;
}