#include "../FormalSpecCPP/task_id_430.cpp"

#include <cassert>  // Required header for assertions
#include <iostream>

#define EPSILON 1e-2 

void testParabolaDirectrix() {
    // Test case 1
    double res1 = ParabolaDirectrix(5, 3, 2);
    assert(std::abs(res1 -  1.95) < EPSILON);

    // Test case 2
    double res2 = ParabolaDirectrix(9, 8, 4);
    assert(std::abs(res2 - 3.97222) < EPSILON);

    // Test case 3
    double res3 = ParabolaDirectrix(2, 4, 6);
    assert(std::abs(res3 - 5.875) < EPSILON);
}

int main() {
    testParabolaDirectrix();
    return 0;
}