#include "task_id_266.cpp"

#include <cassert>  // Required header for assertions

void testLateralSurfaceArea() {
    // Test case 1
    int res1 = LateralSurfaceArea(5);
    assert(res1 == 100);

    // Test case 2
    int res2 = LateralSurfaceArea(9);
    assert(res2 == 324);

    // Test case 3
    int res3 = LateralSurfaceArea(10);
    assert(res3 == 400);
}

int main() {
    testLateralSurfaceArea();
    return 0;
}