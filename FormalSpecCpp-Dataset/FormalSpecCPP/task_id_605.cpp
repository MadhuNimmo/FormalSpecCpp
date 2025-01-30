#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsPrime(unsigned int n) {
    // Precondition: n should be at least 2
    REQUIRE(n >= 2);

    bool result = true;
    unsigned int i = 2;

    // Loop invariant: i should be at least 2 and less than or equal to n/2 + 1
    // Loop invariant: result is true if and only if all numbers from 2 to i-1 do not divide n
    while (i <= n / 2) {
        assert(i >= 2); // Asserting the loop invariant

        if (n % i == 0) {
            result = false;
            break;
        }
        i = i + 1;
    }

    // Postcondition: result should be true if and only if no number from 2 to n-1 divides n
    ENSURE(result == (n == 2 || [&] {
        for (unsigned int k = 2; k < n; ++k) {
            if (n % k == 0) return false;
        }
        return true;
    }()));

    return result;
}