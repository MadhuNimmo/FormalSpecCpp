#include "../FormalSpecCPP/task_id_743.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testRotateRight() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> e1 = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    std::vector<int> res1 = RotateRight(a1, 3);
    assert(res1==e1);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> e2 = {9, 10, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> res2 = RotateRight(a2, 2);
    assert(res2==e2);

    // Test case 3
    std::vector<int> a3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> e3 = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    std::vector<int> res3 = RotateRight(a3, 5);
    assert(res3==e3);
}

int main() {
    testRotateRight();
    return 0;
}