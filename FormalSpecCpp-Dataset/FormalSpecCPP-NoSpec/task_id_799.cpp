#include <cstdint>


uint32_t RotateLeftBits(uint32_t n, int d) {

    // Perform the rotation
    uint32_t result = (n << d) | (n >> (32 - d));


    return result;
}
