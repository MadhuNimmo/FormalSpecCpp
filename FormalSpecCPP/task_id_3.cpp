#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsNonPrime(int n) {
    // Precondition
    REQUIRE(n >= 2);

    bool result = false;
    int i = 2;

    // Loop with invariants
    while (i <= n / 2) {
        assert(i >= 2); // Loop invariant
        assert(result == ( [&]() { // Loop invariant using lambda to encapsulate the existential check
            for (int k = 2; k < i; ++k) {
                if (n % k == 0) return true;
            }
            return false;
        }() ));

        if (n % i == 0) {
            result = true;
            break;
        }
        i = i + 1;
    }

    // Postcondition
    ENSURE(result == ( [&]() { // Postcondition using lambda to encapsulate the existential check
        for (int k = 2; k < n; ++k) {
            if (n % k == 0) return true;
        }
        return false;
    }() ));

    return result;
}