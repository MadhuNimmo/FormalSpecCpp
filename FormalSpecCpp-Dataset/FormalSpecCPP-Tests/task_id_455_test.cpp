#include "task_id_455.cpp"

#include <cassert>  // Required header for assertions

void testMonthHas31Days() {
    // Test case 1
    bool res1 = MonthHas31Days(5);
    assert(res1 == true);

    // Test case 2
    bool res2 = MonthHas31Days(2);
    assert(res2 == false);

    // Test case 3
    bool res3 = MonthHas31Days(6);
    assert(res3 == false);
}

int main() {
    testMonthHas31Days();
    return 0;
}