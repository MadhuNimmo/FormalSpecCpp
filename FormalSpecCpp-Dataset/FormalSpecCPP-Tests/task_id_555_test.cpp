#include "task_id_555.cpp"

#include <cassert>  // Required header for assertions

void testDifferenceSumCubesAndSumNumbers() {
    // Test case 1
    int res1 = DifferenceSumCubesAndSumNumbers(3);
    assert(res1 == 30);

    // Test case 2
    int res2 = DifferenceSumCubesAndSumNumbers(5);
    assert(res2 == 210);

    // Test case 3
    int res3 = DifferenceSumCubesAndSumNumbers(2);
    assert(res3 == 6);
}

int main() {
    testDifferenceSumCubesAndSumNumbers();
    return 0;
}