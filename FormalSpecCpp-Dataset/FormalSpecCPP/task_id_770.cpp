#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int SumOfFourthPowerOfOddNumbers(unsigned int n) {
    // Preconditions
    REQUIRE(n > 0);

    int sum = 0;
    unsigned int i = 1;

    for (unsigned int k = 0; k < n; ++k) {
        // Loop invariants
        assert(0 <= k && k <= n);
        assert(i == 2 * k + 1);
        
        sum += i * i * i * i;  // Add the fourth power of the odd number
        i += 2;  // Move to the next odd number
    }

    // Postconditions
    ENSURE(sum == static_cast<int>((n) * (2 * n + 1) * (24 * n * n * n - 12 * n * n - 14 * n + 7) / 15));

    return sum;
}
