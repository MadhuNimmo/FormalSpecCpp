#include "task_id_807.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testFindFirstOdd() {
    // Test case 1
    std::vector<int> a1 = {1, 3, 5};
    int out1 = FindFirstOdd(a1);
    assert(out1 == 1);

    // Test case 2
    std::vector<int> a2 = {2, 4, 1, 3};
    int out2 = FindFirstOdd(a2);
    assert(out2 == 1);

    // Test case 3
    std::vector<int> a3 = {8, 9, 1};
    int out3 = FindFirstOdd(a3);
    assert(out3 == 9);
}

int main() {
    testFindFirstOdd();
    return 0;
}