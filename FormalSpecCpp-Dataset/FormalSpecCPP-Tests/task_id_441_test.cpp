#include "../FormalSpecCPP/task_id_441.cpp"

#include <cassert>  // Required header for assertions

void testCubeSurfaceArea() {
    // Test case 1
    int out1 = CubeSurfaceArea(5);
    assert(out1 == 150);

    // Test case 2
    int out2 = CubeSurfaceArea(3);
    assert(out2 == 54);

    // Test case 3
    int out3 = CubeSurfaceArea(10);
    assert(out3 == 600);
}

int main() {
    testCubeSurfaceArea();
    return 0;
}