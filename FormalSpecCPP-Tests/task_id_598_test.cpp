#include "../FormalSpecCPP/task_id_598.cpp"

#include <cassert>  // Required header for assertions

void testIsArmstrong() {
    // Test case 1
    bool res1 = IsArmstrong(153);
    assert(res1 == true);

    // Test case 2
    bool res2 = IsArmstrong(259);
    assert(res2 == false);

    // Test case 3
    bool res3 = IsArmstrong(4458);
    assert(res3 == false);
}

int main() {
    testIsArmstrong();
    return 0;
}