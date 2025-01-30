#include "../FormalSpecCPP-NoSpec/task_id_770.cpp"

#include <cassert>  // Required header for assertions

void testSumOfFourthPowerOfOddNumbers() {
    // Test case 1
    int out1 = SumOfFourthPowerOfOddNumbers(2);
    assert(out1 == 82);

    // Test case 2
    int out2 = SumOfFourthPowerOfOddNumbers(3);
    assert(out2 == 707);

    // Test case 3
    int out3 = SumOfFourthPowerOfOddNumbers(4);
    assert(out3 == 3108);
}

int main() {
    testSumOfFourthPowerOfOddNumbers();
    return 0;
}