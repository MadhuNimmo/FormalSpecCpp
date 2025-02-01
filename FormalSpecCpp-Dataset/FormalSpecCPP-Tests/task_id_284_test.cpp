#include "task_id_284.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

// Function prototype for AllElementsEqual
bool AllElementsEqual(const std::vector<int>& arr, int value);

void testAllElementsEqual() {
    // Test case 1
    std::vector<int> a1 = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    bool res1 = AllElementsEqual(a1, 3);
    assert(res1 == false);

    // Test case 2
    std::vector<int> a2 = {1, 1, 1, 1, 1, 1, 1};
    bool res2 = AllElementsEqual(a2, 1);
    assert(res2 == true);

    // Test case 3
    std::vector<int> a3 = {5, 6, 7, 4, 8};
    bool res3 = AllElementsEqual(a3, 6);
    assert(res3 == false);
}

int main() {
    testAllElementsEqual();
    return 0;
}