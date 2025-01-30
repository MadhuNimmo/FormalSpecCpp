#include "../FormalSpecCPP/task_id_762.cpp"

#include <cassert>  // Required header for assertions

void testIsMonthWith30Days() {
    // Test case 1
    bool out1 = IsMonthWith30Days(6);
    assert(out1 == true);

    // Test case 2
    bool out2 = IsMonthWith30Days(2);
    assert(out2 == false);

    // Test case 3
    bool out3 = IsMonthWith30Days(12);
    assert(out3 == false);
}

int main() {
    testIsMonthWith30Days();
    return 0;
}