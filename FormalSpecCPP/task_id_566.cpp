#include <cassert>
#include <cmath>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

unsigned int Power10(unsigned int n) {
    if (n == 0) return 1;
    return 10 * Power10(n - 1);
}

unsigned int NumberOfDigits(unsigned int n) {
    if (n <= 9) return 1;
    return 1 + NumberOfDigits(n / 10);
}

unsigned int SumDigits(unsigned int n) {
    unsigned int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

unsigned int SumOfDigits(unsigned int number) {
    REQUIRE(number >= 0); // Precondition

    unsigned int sum = 0;
    unsigned int n = number;
    unsigned int ndigits = NumberOfDigits(number);
    unsigned int pmax = Power10(ndigits);
    unsigned int p = 1;
    unsigned int i = 0;

    while (n > 0) {
        assert(1 <= p && p <= pmax); // Loop invariant
        assert(i <= ndigits); // Loop invariant
        assert(sum >= 0); // Loop invariant
        assert(sum == SumDigits(number % p)); // Loop invariant

        unsigned int digit = n % 10;
        sum += digit;
        n /= 10;
        i++;
        p = Power10(i);
    }

    assert(n == 0); // Post loop condition
    assert(p == pmax); // Post loop condition
    ENSURE(sum >= 0); // Postcondition
    ENSURE(sum == SumDigits(number)); // Postcondition

    return sum;
}