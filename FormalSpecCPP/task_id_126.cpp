#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int SumOfCommonDivisors(int a, int b) {
    // Preconditions
    REQUIRE(a > 0 && b > 0);

    int sum = 0;
    int i = 1;

    // Loop to calculate the sum of common divisors
    while (i <= a && i <= b) {
        // Loop invariants
        assert(1 <= i && i <= a + 1 && i <= b + 1);
        assert(sum >= 0);

        if (a % i == 0 && b % i == 0) {
            sum += i;
        }
        i++;
    }

    // Postconditions
    ENSURE(sum >= 0);

    return sum;
}