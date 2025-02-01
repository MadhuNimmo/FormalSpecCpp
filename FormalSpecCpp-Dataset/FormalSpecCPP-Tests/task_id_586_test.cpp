#include "task_id_586.cpp"

#include <vector>
#include <cassert>

void testSplitAndAppend() {
    // Test case 1
    std::vector<int> l1 = {12, 10, 5, 6, 52, 36};
    std::vector<int> e1 = {5, 6, 52, 36, 12, 10};
    std::vector<int> res1 = SplitAndAppend(l1, 2);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> l2 = {1, 2, 3, 4};
    std::vector<int> e2 = {2, 3, 4, 1};
    std::vector<int> res2 = SplitAndAppend(l2, 1);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> l3 = {0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<int> e3 = {3, 4, 5, 6, 7, 0, 1, 2};
    std::vector<int> res3 = SplitAndAppend(l3, 3);
    assert(res3 == e3);
}

int main() {
    testSplitAndAppend();
    return 0;
}