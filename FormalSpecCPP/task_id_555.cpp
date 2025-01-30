#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int DifferenceSumCubesAndSumNumbers(int n) {
    // Preconditions
    REQUIRE(n >= 0);

    // Variables to store the sum of cubes and sum of numbers
    int sumCubes = 0;
    int sumNumbers = 0;

    // Loop to calculate the sum of cubes and sum of numbers
    for (int i = 1; i <= n; ++i) {
        // Loop invariants
        assert(0 <= i && i <= n + 1);
        assert(sumCubes == (i - 1) * (i - 1) * i * i / 4);
        assert(sumNumbers == (i - 1) * i / 2);

        sumCubes += i * i * i;
        sumNumbers += i;
    }

    // Calculate the difference
    int diff = sumCubes - sumNumbers;

    // Postcondition
    ENSURE(diff == (n * n * (n + 1) * (n + 1)) / 4 - (n * (n + 1)) / 2);

    return diff;
}