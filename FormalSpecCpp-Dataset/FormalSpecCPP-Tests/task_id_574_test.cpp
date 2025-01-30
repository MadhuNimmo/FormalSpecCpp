#include "../FormalSpecCPP/task_id_574.cpp"

#include <cassert>
#include <cmath>

void testCylinderSurfaceArea() {
    // Test case 1
    long res1 = CylinderSurfaceArea(10.0, 5.0);
    assert(res1==static_cast<long>(942.45));

    // Test case 2
    long res2 = CylinderSurfaceArea(4.0, 5.0);
    assert(res2==static_cast<long>(226.188));

    // Test case 3
    long res3 = CylinderSurfaceArea(4.0, 10.0);
    assert(res3==static_cast<long>(351.848));
}

int main() {
    testCylinderSurfaceArea();
    return 0;
}