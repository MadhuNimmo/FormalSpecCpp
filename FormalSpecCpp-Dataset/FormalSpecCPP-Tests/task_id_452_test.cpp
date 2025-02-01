#include "task_id_452.cpp"

#include <iostream>
#include <cassert>  // Required header for assertions

void testCalculateLoss() {
    // Test case 1
    int res1 = CalculateLoss(1500, 1200);
    assert(res1 == 0);

    // Test case 2
    int res2 = CalculateLoss(100, 200);
    assert(res2 == 100);

    // Test case 3
    int res3 = CalculateLoss(2000, 5000);
    assert(res3 == 3000);
}

int main() {
    testCalculateLoss();
    return 0;
}