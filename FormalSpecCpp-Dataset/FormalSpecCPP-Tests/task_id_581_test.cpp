#include "../FormalSpecCPP/task_id_581.cpp"

#include <cassert>  // Required header for assertions

void testSquarePyramidSurfaceArea() {
    // Test case 1
    double res1 = SquarePyramidSurfaceArea(3.0, 4.0);
    assert(res1 == 33.0);

    // Test case 2
    double res2 = SquarePyramidSurfaceArea(4.0, 5.0);
    assert(res2 == 56.0);

    // Test case 3
    double res3 = SquarePyramidSurfaceArea(1.0, 1.0);
    assert(res3 == 3.0);
}

int main() {
    testSquarePyramidSurfaceArea();
    return 0;
}