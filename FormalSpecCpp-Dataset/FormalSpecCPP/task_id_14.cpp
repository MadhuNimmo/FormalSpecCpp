#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int TriangularPrismVolume(unsigned int base, unsigned int height, unsigned int length) {
    // Preconditions
    REQUIRE(base > 0);
    REQUIRE(height > 0);
    REQUIRE(length > 0);

    unsigned int volume = (base * height * length) / 2;

    // Postcondition
    ENSURE(volume == (base * height * length) / 2);

    return volume;
}