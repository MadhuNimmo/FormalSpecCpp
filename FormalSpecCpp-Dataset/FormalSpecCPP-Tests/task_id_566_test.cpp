#include "../FormalSpecCPP/task_id_566.cpp"

#include <cassert>  // Required header for assertions

void testSumOfDigits() {
    // Test case 1
    int out1 = SumOfDigits(345);
    assert(out1 == 12);

    // Test case 2
    int out2 = SumOfDigits(12);
    assert(out2 == 3);

    // Test case 3
    int out3 = SumOfDigits(97);
    assert(out3 == 16);
}

int main() {
    testSumOfDigits();
    return 0;
}