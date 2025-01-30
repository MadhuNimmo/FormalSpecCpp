#include "../FormalSpecCPP-NoSpec/task_id_268.cpp"

#include <cassert>  // Required header for assertions

void testStarNumber() {
    // Test case 1
    int res1 = StarNumber(3);
    assert(res1 == 37);

    // Test case 2
    int res2 = StarNumber(4);
    assert(res2 == 73);

    // Test case 3
    int res3 = StarNumber(5);
    assert(res3 == 121);
}

int main() {
    testStarNumber();
    return 0;
}