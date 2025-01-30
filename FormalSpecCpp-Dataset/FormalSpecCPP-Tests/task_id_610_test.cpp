#include "../FormalSpecCPP/task_id_610.cpp"

#include <cassert>
#include <vector>

void testRemoveElement() {
    // Test case 1
    std::vector<int> a1 = {1, 1, 2, 3, 4, 4, 5, 1};
    std::vector<int> e1 = {1, 1, 2, 4, 4, 5, 1};
    std::vector<int> res1 = RemoveElement(a1, 3);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> a2 = {0, 0, 1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8, 9, 4, 4};
    std::vector<int> e2 = {0, 0, 1, 2, 4, 4, 5, 6, 6, 6, 7, 8, 9, 4, 4};
    std::vector<int> res2 = RemoveElement(a2, 4);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> a3 = {10, 10, 15, 19, 18, 18, 17, 26, 26, 17, 18, 10};
    std::vector<int> e3 = {10, 10, 15, 19, 18, 17, 26, 26, 17, 18, 10};
    std::vector<int> res3 = RemoveElement(a3, 5);
    assert(res3 == e3);
}

int main() {
    testRemoveElement();
    return 0;
}