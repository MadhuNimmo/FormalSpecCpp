#include "../FormalSpecCPP-NoSpec/task_id_85.cpp"

#include <cassert>  // Required for assert
#include <cmath>     // Required for fabs

// Assuming the function SphereSurfaceArea is defined elsewhere and returns a double
extern double SphereSurfaceArea(double radius);

void testSphereSurfaceArea() {
    // Test case 1
    double res1 = SphereSurfaceArea(10);
    assert(fabs(res1 - 1256.6370614359173) < 1e-9);

    // Test case 2
    double res2 = SphereSurfaceArea(15);
    assert(fabs(res2 - 2827.4333882308138) < 1e-9);

    // Test case 3
    double res3 = SphereSurfaceArea(20);
    assert(fabs(res3 - 5026.548245743669) < 1e-9);
}

int main() {
    testSphereSurfaceArea();
    return 0;
}