#include "../FormalSpecCPP-NoSpec/task_id_803.cpp"

#include <cassert>  // Required header for assertions

void testIsPerfectSquare() {
    // Test case 1
    bool out1 = IsPerfectSquare(10);
    assert(out1 == false);

    // Test case 2
    bool out2 = IsPerfectSquare(36);
    assert(out2 == true);

    // Test case 3
    bool out3 = IsPerfectSquare(14);
    assert(out3 == false);
}

int main() {
    testIsPerfectSquare();
    return 0;
}