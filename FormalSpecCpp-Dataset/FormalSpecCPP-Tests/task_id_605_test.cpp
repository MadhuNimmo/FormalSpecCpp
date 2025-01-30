#include "../FormalSpecCPP/task_id_605.cpp"

#include <cassert>  // Required header for assertions

void testIsPrime() {
    // Test case 1
    bool out1 = IsPrime(13);
    assert(out1 == true);

    // Test case 2
    bool out2 = IsPrime(7);
    assert(out2 == true);

    // Test case 3
    bool out3 = IsPrime(1010);
    assert(out3 == false);
}

int main() {
    testIsPrime();
    return 0;
}