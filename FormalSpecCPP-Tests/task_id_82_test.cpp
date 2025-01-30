#include "../FormalSpecCPP/task_id_82.cpp"

#include <cassert>  // Required header for assertions
#include <cmath>    // Required for floating-point comparison

void testSphereVolume() {
    // Test case 1
    double res1 = SphereVolume(10);
    assert(fabs(res1 - 4188.790204786391) < 1e-9);

    // Test case 2
    double res2 = SphereVolume(25);
    assert(fabs(res2 - 65449.84694978735) < 1e-9);

    // Test case 3
    double res3 = SphereVolume(20);
    assert(fabs(res3 - 33510.32163829113) < 1e-9);
}

int main() {
    testSphereVolume();
    return 0;
}