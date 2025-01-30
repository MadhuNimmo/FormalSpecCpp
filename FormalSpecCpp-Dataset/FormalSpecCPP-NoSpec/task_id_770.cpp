int SumOfFourthPowerOfOddNumbers(unsigned int n) {

    int sum = 0;
    unsigned int i = 1;

    for (unsigned int k = 0; k < n; ++k) {

        sum += i * i * i * i;  // Add the fourth power of the odd number
        i += 2;  // Move to the next odd number
    }


    return sum;
}
