int SumOfSquaresOfFirstNOddNumbers(unsigned int n) {

    unsigned int sum = 0;
    unsigned int i = 1;

    for (unsigned int k = 0; k < n; ++k) {

        sum += i * i;
        i += 2;
    }


    return sum;
}
