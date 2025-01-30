#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int SumOfSquaresOfFirstNOddNumbers(unsigned int n) {
    // Precondition
    REQUIRE(n >= 0);

    unsigned int sum = 0;
    unsigned int i = 1;

    for (unsigned int k = 0; k < n; ++k) {
        // Loop invariants
        assert(0 <= k && k <= n);
        assert(sum == k * (2 * k - 1) * (2 * k + 1) / 3);
        assert(i == 2 * k + 1);

        sum += i * i;
        i += 2;
    }

    // Postcondition
    ENSURE(sum == (n * (2 * n - 1) * (2 * n + 1)) / 3);

    return sum;
}