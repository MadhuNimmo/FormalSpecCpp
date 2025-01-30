// Function to calculate factorial
unsigned int Factorial(unsigned int n) {

    if (n == 0) {
        return 1;
    } else {
        unsigned int result = n * Factorial(n - 1);
        return result;
    }
}

// Function to calculate the factorial of the last digit of a number
unsigned int FactorialOfLastDigit(unsigned int n) {

    unsigned int lastDigit = n % 10;
    unsigned int fact = Factorial(lastDigit);

    return fact;
}
