#include <cstddef>


unsigned int CenteredHexagonalNumber(size_t n) {

    // Calculation to find the centered hexagonal number
    unsigned int result = 3 * n * (n - 1) + 1;


    return result;
}
