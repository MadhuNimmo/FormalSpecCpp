#include "task_id_59.cpp"

#include <cassert>  // Required header for assertions

void testNthOctagonalNumber() {
    // Test case 1
    int res1 = NthOctagonalNumber(5);
    assert(res1 == 65);

    // Test case 2
    int res2 = NthOctagonalNumber(10);
    assert(res2 == 280);

    // Test case 3
    int res3 = NthOctagonalNumber(15);
    assert(res3 == 645);
}

int main() {
    testNthOctagonalNumber();
    return 0;
}