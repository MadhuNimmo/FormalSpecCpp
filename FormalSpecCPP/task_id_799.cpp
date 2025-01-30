#include <cassert>
#include <cstdint>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

uint32_t RotateLeftBits(uint32_t n, int d) {
    // Preconditions
    REQUIRE(0 <= d && d < 32);

    // Perform the rotation
    uint32_t result = (n << d) | (n >> (32 - d));

    // Postconditions
    ENSURE(result == ((n << d) | (n >> (32 - d))));

    return result;
}