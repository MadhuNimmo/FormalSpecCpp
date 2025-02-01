#include "task_id_755.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector
#include <iostream>

void testSecondSmallest() {
    // Test case 1
    std::vector<int> a1 = {1, 2, -8, -2, 0, -2};
    int out1 = SecondSmallest(a1);
    assert(out1 == -2);

    // Test case 2
    std::vector<int> a2 = {1, 1, 5, 0, 2, -2, -2};
    int out2 = SecondSmallest(a2);
    assert(out2 == 0);

    // Test case 3
    std::vector<int> a3 = {-2, -3, -1};
    int out3 = SecondSmallest(a3);
    assert(out3 == -2);
}

int main() {
    testSecondSmallest();
    return 0;
}