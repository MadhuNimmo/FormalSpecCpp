#include "../FormalSpecCPP/task_id_304.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testElementAtIndexAfterRotation() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5};
    int res1 = ElementAtIndexAfterRotation(a1, 2, 3);
    assert(res1 == 2);

    // Test case 2
    std::vector<int> a2 = {10, 20, 30, 40, 50};
    int res2 = ElementAtIndexAfterRotation(a2, 10, 1);
    assert(res2 == 20);

    // Test case 3
    std::vector<int> a3 = {7, 8, 9, 10, 11};
    int res3 = ElementAtIndexAfterRotation(a3, 15, 2);
    assert(res3 == 9);
}

int main() {
    testElementAtIndexAfterRotation();
    return 0;
}