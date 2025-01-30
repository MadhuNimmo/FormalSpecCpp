#include "../FormalSpecCPP/task_id_276.cpp"

#include <cassert>  // Required header for assertions
#include <cmath>    // Required for comparing floating-point numbers
#include <iostream>

#define EPSILON 1e-2 

void testCylinderVolume() {
    // Test case 1
    double res1 = CylinderVolume(10.0, 5.0);
    assert(std::abs(res1 - 1570.795) < EPSILON);

    // Test case 2
    double res2 = CylinderVolume(4.0, 5.0);
    assert(std::abs(res2 - 251.327) < EPSILON);

    // Test case 3
    double res3 = CylinderVolume(4.0, 10.0);
    assert(std::abs(res3 - 502.654) < EPSILON);
}

int main() {
    testCylinderVolume();
    return 0;
}