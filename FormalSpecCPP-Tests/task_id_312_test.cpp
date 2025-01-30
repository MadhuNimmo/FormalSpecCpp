#include "../FormalSpecCPP/task_id_312.cpp"

#include <cassert>  // Required header for assertions
#include <cmath>     // Required header for math functions

void testConeVolume() {
    // Test case 1
    double res1 = ConeVolume(5.0, 12.0);
    assert(fabs(res1 - 314.15926535897927) < 1e-9);

    // Test case 2
    double res2 = ConeVolume(10.0, 15.0);
    assert(fabs(res2 - 1570.7963267948965) < 1e-9);

    // Test case 3
    double res3 = ConeVolume(19.0, 17.0);
    assert(fabs(res3 - 6426.651371693521) < 1e-9);
}

int main() {
    testConeVolume();
    return 0;
}