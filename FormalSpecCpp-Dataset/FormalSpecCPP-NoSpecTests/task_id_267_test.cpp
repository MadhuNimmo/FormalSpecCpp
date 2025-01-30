#include "../FormalSpecCPP-NoSpec/task_id_267.cpp"

#include <cassert>  // Required header for assertions

void testSumOfSquaresOfFirstNOddNumbers() {
    // Test case 1
    int out1 = SumOfSquaresOfFirstNOddNumbers(2);
    assert(out1 == 10);

    // Test case 2
    int out2 = SumOfSquaresOfFirstNOddNumbers(3);
    assert(out2 == 35);

    // Test case 3
    int out3 = SumOfSquaresOfFirstNOddNumbers(4);
    assert(out3 == 84);
}

int main() {
    testSumOfSquaresOfFirstNOddNumbers();
    return 0;
}