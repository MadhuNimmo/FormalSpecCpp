#include "../FormalSpecCPP-NoSpec/task_id_135.cpp"

#include <cassert>  // Required header for assertions

void testNthHexagonalNumber() {
    // Test case 1
    int res1 = NthHexagonalNumber(10);
    assert(res1 == 190);

    // Test case 2
    int res2 = NthHexagonalNumber(5);
    assert(res2 == 45);

    // Test case 3
    int res3 = NthHexagonalNumber(7);
    assert(res3 == 91);
}

int main() {
    testNthHexagonalNumber();
    return 0;
}