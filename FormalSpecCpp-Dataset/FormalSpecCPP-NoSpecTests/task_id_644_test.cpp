#include "../FormalSpecCPP-NoSpec/task_id_644.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testReverseUptoK() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> e1 = {4, 3, 2, 1, 5, 6};
    std::vector<int> res1 = ReverseUptoK(a1, 4);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> a2 = {4, 5, 6, 7};
    std::vector<int> e2 = {5, 4, 6, 7};
    std::vector<int> res2 = ReverseUptoK(a2, 2);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> a3 = {9, 8, 7, 6, 5};
    std::vector<int> e3 = {7, 8, 9, 6, 5};
    std::vector<int> res3 = ReverseUptoK(a3, 3);
    assert(res3 == e3);
}

int main() {
    testReverseUptoK();
    return 0;
}