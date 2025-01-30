#include "../FormalSpecCPP/task_id_126.cpp"

#include <cassert>  // Required header for assertions

void testSumOfCommonDivisors() {
    // Test case 1
    int out1 = SumOfCommonDivisors(10, 15);
    assert(out1 == 6);

    // Test case 2
    int out2 = SumOfCommonDivisors(100, 150);
    assert(out2 == 93);

    // Test case 3
    int out3 = SumOfCommonDivisors(4, 6);
    assert(out3 == 3);
}

int main() {
    testSumOfCommonDivisors();
    return 0;
}