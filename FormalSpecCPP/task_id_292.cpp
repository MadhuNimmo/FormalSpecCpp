#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int Quotient(int a, int b) {
    // Precondition: b must not be zero
    REQUIRE(b != 0);

    int result = a / b;

    // Postcondition: result must be equal to a divided by b
    ENSURE(result == a / b);

    return result;
}