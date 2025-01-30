// Function to calculate the nth nonagonal number
unsigned int NthNonagonalNumber(unsigned int n) {

    // Calculate the nth nonagonal number
    unsigned int number = n * (7 * n - 5) / 2;


    return number;
}
