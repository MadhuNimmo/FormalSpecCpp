int DifferenceSumCubesAndSumNumbers(int n) {

    // Variables to store the sum of cubes and sum of numbers
    int sumCubes = 0;
    int sumNumbers = 0;

    // Loop to calculate the sum of cubes and sum of numbers
    for (int i = 1; i <= n; ++i) {

        sumCubes += i * i * i;
        sumNumbers += i;
    }

    // Calculate the difference
    int diff = sumCubes - sumNumbers;


    return diff;
}
