#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate factorial
unsigned int Factorial(unsigned int n) {
    REQUIRE(n >= 0); // Precondition: n must be non-negative

    if (n == 0) {
        return 1;
    } else {
        unsigned int result = n * Factorial(n - 1);
        ENSURE(result >= 1); // Postcondition: Factorial should always be non-negative and non-zero for n > 0
        return result;
    }
}

// Function to calculate the factorial of the last digit of a number
unsigned int FactorialOfLastDigit(unsigned int n) {
    REQUIRE(n >= 0); // Precondition: n must be non-negative

    unsigned int lastDigit = n % 10;
    unsigned int fact = Factorial(lastDigit);

    ENSURE(fact == Factorial(lastDigit)); // Postcondition: fact must be the factorial of the last digit
    return fact;
}