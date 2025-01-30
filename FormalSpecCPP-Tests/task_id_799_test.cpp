#include "../FormalSpecCPP/task_id_799.cpp"

#include <cassert>  // Required header for assertions

void testRotateLeftBits() {
    // Test case 1
    int res1 = RotateLeftBits(16, 2);
    assert(res1 == 64);

    // Test case 2
    int res2 = RotateLeftBits(10, 2);
    assert(res2 == 40);

    // Test case 3
    int res3 = RotateLeftBits(99, 3);
    assert(res3 == 792);
}

int main() {
    testRotateLeftBits();
    return 0;
}