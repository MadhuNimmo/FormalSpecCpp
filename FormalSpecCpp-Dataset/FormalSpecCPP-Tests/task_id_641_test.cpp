#include "task_id_641.cpp"

#include <cassert>  // Required header for assertions

void testNthNonagonalNumber() {
    // Test case 1
    int res1 = NthNonagonalNumber(10);
    assert(res1 == 325);

    // Test case 2
    int res2 = NthNonagonalNumber(15);
    assert(res2 == 750);

    // Test case 3
    int res3 = NthNonagonalNumber(18);
    assert(res3 == 1089);
}

int main() {
    testNthNonagonalNumber();
    return 0;
}