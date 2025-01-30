#include "../FormalSpecCPP-NoSpec/task_id_86.cpp"

#include <cassert>  // Required header for assertions

void testCenteredHexagonalNumber() {
    // Test case 1
    int res1 = CenteredHexagonalNumber(10);
    assert(res1 == 271);

    // Test case 2
    int res2 = CenteredHexagonalNumber(2);
    assert(res2 == 7);

    // Test case 3
    int res3 = CenteredHexagonalNumber(9);
    assert(res3 == 217);
}

int main() {
    testCenteredHexagonalNumber();
    return 0;
}