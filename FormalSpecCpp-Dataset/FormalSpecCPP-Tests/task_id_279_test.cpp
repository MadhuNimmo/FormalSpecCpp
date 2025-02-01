#include "task_id_279.cpp"

#include <cassert>  // Required header for assertions

void testNthDecagonalNumber() {
    // Test case 1
    int res1 = NthDecagonalNumber(3);
    assert(res1 == 27);

    // Test case 2
    int res2 = NthDecagonalNumber(7);
    assert(res2 == 175);

    // Test case 3
    int res3 = NthDecagonalNumber(10);
    assert(res3 == 370);
}

int main() {
    testNthDecagonalNumber();
    return 0;
}