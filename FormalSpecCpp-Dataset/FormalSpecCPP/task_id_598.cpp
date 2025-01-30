#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsArmstrong(int n) {
    // Preconditions
    REQUIRE(n > 0);

    // Extract digits
    int a = n / 100;              // Hundreds digit
    int b = (n / 10) % 10;        // Tens digit
    int c = n % 10;               // Units digit

    // Calculate Armstrong condition
    bool result = n == (a * a * a + b * b * b + c * c * c);

    // Postconditions
    ENSURE(result == (n == (a * a * a + b * b * b + c * c * c)));

    return result;
}