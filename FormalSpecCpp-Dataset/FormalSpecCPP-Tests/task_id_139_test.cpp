#include "../FormalSpecCPP/task_id_139.cpp"

#include <cassert>  // Required header for assertions
#include <cmath>    // Required header for M_PI

// Assuming the CircleCircumference function is defined as follows:
// double CircleCircumference(double radius) {
//     return 2 * M_PI * radius;
// }

void testCircleCircumference() {
    // Test case 1
    double res1 = CircleCircumference(10);
    assert(fabs(res1 - 62.83185307179586476920) < 1e-12);

    // Test case 2
    double res2 = CircleCircumference(5);
    assert(fabs(res2 - 31.41592653589793238460) < 1e-12);

    // Test case 3
    double res3 = CircleCircumference(4);
    assert(fabs(res3 - 25.13274122871834590768) < 1e-12);
}

int main() {
    testCircleCircumference();
    return 0;
}