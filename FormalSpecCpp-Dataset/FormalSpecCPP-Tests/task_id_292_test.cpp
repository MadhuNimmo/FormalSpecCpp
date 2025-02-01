#include "task_id_292.cpp"

#include <cassert>  // Required header for assertions

void testQuotient() {
    // Test case 1
    int res1 = Quotient(10, 3);
    assert(res1 == 3);

    // Test case 2
    int res2 = Quotient(4, 2);
    assert(res2 == 2);

    // Test case 3
    int res3 = Quotient(20, 5);
    assert(res3 == 4);
}

int main() {
    testQuotient();
    return 0;
}