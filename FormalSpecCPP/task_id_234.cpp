#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int CubeVolume(unsigned int size) {
    // Precondition: size must be greater than 0
    REQUIRE(size > 0);

    unsigned int volume = size * size * size;

    // Postcondition: volume must be equal to size cubed
    ENSURE(volume == size * size * size);

    return volume;
}