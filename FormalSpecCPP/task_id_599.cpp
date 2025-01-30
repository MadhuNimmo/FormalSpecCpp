#include <cassert>
#include <cstddef>
#include <tuple>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::tuple<int, double> SumAndAverage(int n) {
    // Preconditions
    REQUIRE(n > 0);

    int sum = 0;
    double average = 0.0;

    for (int i = 1; i <= n; ++i) {
        // Loop invariants
        assert(0 <= i && i <= n + 1);
        assert(sum == (i - 1) * i / 2);

        sum += i;
    }

    average = static_cast<double>(sum) / n;

    // Postconditions
    ENSURE(sum == n * (n + 1) / 2);
    ENSURE(average == static_cast<double>(sum) / n);

    return std::make_tuple(sum, average);
}