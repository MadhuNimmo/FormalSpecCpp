#include "../FormalSpecCPP-NoSpec/task_id_89.cpp"

#include <cassert>  // Required header for assertions

void testClosestSmaller() {
    // Test case 1
    int res1 = ClosestSmaller(11);
    assert(res1 == 10);

    // Test case 2
    int res2 = ClosestSmaller(7);
    assert(res2 == 6);

    // Test case 3
    int res3 = ClosestSmaller(12);
    assert(res3 == 11);
}

int main() {
    testClosestSmaller();
    return 0;
}