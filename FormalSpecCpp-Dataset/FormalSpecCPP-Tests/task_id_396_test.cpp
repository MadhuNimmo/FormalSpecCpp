#include "task_id_396.cpp"

#include <cassert>  // Required header for assertions
#include <string>   // Required header for string usage

void testStartAndEndWithSameChar() {
    // Test case 1
    bool res1 = StartAndEndWithSameChar("abba");
    assert(res1 == true);

    // Test case 2
    bool res2 = StartAndEndWithSameChar("a");
    assert(res2 == true);

    // Test case 3
    bool res3 = StartAndEndWithSameChar("abcd");
    assert(res3 == false);
}

int main() {
    testStartAndEndWithSameChar();
    return 0;
}