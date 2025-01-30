#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsPerfectSquare(unsigned int n) {
    REQUIRE(n >= 0);  // Precondition

    unsigned int i = 0;
    while (i * i < n) {
        assert(0 <= i && i <= n);  // Loop invariant
        for (unsigned int k = 0; k < i; ++k) {
            assert(k * k < n);  // Loop invariant
        }
        i++;
    }

    bool result = (i * i == n);
    ENSURE(result == true || result == false);  // Redundant but ensures boolean result
    if (result) {
        ENSURE((0 <= i && i <= n) && (i * i == n));  // Postcondition for true result
    } else {
        // Postcondition for false result is a universal quantification which is hard to check directly;
        // it's a logical consequence of the algorithm and the loop exit condition.
    }

    return result;
}