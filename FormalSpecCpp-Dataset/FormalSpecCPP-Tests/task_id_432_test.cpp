#include "task_id_432.cpp"

#include <cassert>  // Required header for assertions

void testMedianLength() {
    // Test case 1
    double res1 = MedianLength(15, 25);
    assert(res1 == 20.0);

    // Test case 2
    double res2 = MedianLength(10, 20);
    assert(res2 == 15.0);

    // Test case 3
    double res3 = MedianLength(6, 9);
    assert(res3 == 7.5);
}

int main() {
    testMedianLength();
    return 0;
}