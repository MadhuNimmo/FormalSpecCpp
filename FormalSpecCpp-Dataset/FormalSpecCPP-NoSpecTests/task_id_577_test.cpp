#include "../FormalSpecCPP-NoSpec/task_id_577.cpp"

#include <cassert>  // Required header for assertions

void testFactorialOfLastDigit() {
    // Test case 1
    int res1 = FactorialOfLastDigit(4);
    assert(res1 == 24);

    // Test case 2
    int res2 = FactorialOfLastDigit(21);
    assert(res2 == 1);

    // Test case 3
    int res3 = FactorialOfLastDigit(30);
    assert(res3 == 1);
}

int main() {
    testFactorialOfLastDigit();
    return 0;
}