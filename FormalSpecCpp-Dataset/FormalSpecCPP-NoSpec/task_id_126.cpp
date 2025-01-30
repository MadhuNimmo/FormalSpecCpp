int SumOfCommonDivisors(int a, int b) {

    int sum = 0;
    int i = 1;

    // Loop to calculate the sum of common divisors
    while (i <= a && i <= b) {

        if (a % i == 0 && b % i == 0) {
            sum += i;
        }
        i++;
    }


    return sum;
}
