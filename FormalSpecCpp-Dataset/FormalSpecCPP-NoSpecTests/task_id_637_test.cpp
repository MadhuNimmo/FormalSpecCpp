#include "../FormalSpecCPP-NoSpec/task_id_637.cpp"

#include <cassert>  // Required header for assertions

void testIsBreakEven() {
    // Test case 1
    bool res1 = IsBreakEven(1500, 1200);
    assert(res1 == false);

    // Test case 2
    bool res2 = IsBreakEven(100, 100);
    assert(res2 == true);

    // Test case 3
    bool res3 = IsBreakEven(2000, 5000);
    assert(res3 == false);
}

int main() {
    testIsBreakEven();
    return 0;
}