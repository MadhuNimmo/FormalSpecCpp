#include "../FormalSpecCPP-NoSpec/task_id_234.cpp"

#include <cassert>  // Required header for assertions

void testCubeVolume() {
    // Test case 1
    int out1 = CubeVolume(3);
    assert(out1 == 27);

    // Test case 2
    int out2 = CubeVolume(2);
    assert(out2 == 8);

    // Test case 3
    int out3 = CubeVolume(5);
    assert(out3 == 125);  // Corrected expected value from 25 to 125
}

int main() {
    testCubeVolume();
    return 0;
}