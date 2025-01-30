#include "../FormalSpecCPP/task_id_435.cpp"

#include <cassert>  // Required header for assertions

void testLastDigit() {
    // Test case 1
    int out1 = LastDigit(123);
    assert(out1 == 3);

    // Test case 2
    int out2 = LastDigit(25);
    assert(out2 == 5);

    // Test case 3
    int out3 = LastDigit(30);
    assert(out3 == 0);
}

int main() {
    testLastDigit();
    return 0;
}