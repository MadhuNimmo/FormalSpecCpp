#include "../FormalSpecCPP/task_id_80.cpp"

#include <cassert>  // Required header for assertions

void testTetrahedralNumber() {
    // Test case 1
    int res1 = TetrahedralNumber(5);
    assert(res1 == 35);

    // Test case 2
    int res2 = TetrahedralNumber(6);
    assert(res2 == 56);

    // Test case 3
    int res3 = TetrahedralNumber(7);
    assert(res3 == 84);
}

int main() {
    testTetrahedralNumber();
    return 0;
}