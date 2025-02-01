#include "task_id_3.cpp"

#include <cassert>  // Required header for assertions

void testIsNonPrime() {
    // Test case 1
    bool res1 = IsNonPrime(2);
    assert(res1 == false);

    // Test case 2
    bool res2 = IsNonPrime(10);
    assert(res2 == true);

    // Test case 3
    bool res3 = IsNonPrime(35);
    assert(res3 == true);
}

int main() {
    testIsNonPrime();
    return 0;
}