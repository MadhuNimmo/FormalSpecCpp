#include "../FormalSpecCPP-NoSpec/task_id_233.cpp"

#include <cassert>  // Required header for assertions
#include <cmath>    // Required header for M_PI

const long double EPSILON = 1e-6;

void testCylinderLateralSurfaceArea() {
    // Test case 1
    long double res1 = CylinderLateralSurfaceArea(10.0, 5.0);
    assert(std::abs(res1 - 314.15926535897932384600L) < EPSILON);

    // Test case 2
    long double res2 = CylinderLateralSurfaceArea(4.0, 5.0);
    assert(std::abs(res2 - 125.66370614359172953840L) < EPSILON);

    // Test case 3
    long double res3 = CylinderLateralSurfaceArea(4.0, 10.0);
    assert(std::abs(res3 - 251.32741228718345907680L) < EPSILON);
}

int main() {
    testCylinderLateralSurfaceArea();
    return 0;
}