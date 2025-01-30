#include "../FormalSpecCPP-NoSpec/task_id_240.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testReplaceLastElement() {
    // Test case 1
    std::vector<int> a1 = {1, 3, 5, 7, 9, 10};
    std::vector<int> a2 = {2, 4, 6, 8};
    std::vector<int> e1 = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    std::vector<int> res1 = ReplaceLastElement(a1, a2);
    assert(res1==e1);

    // Test case 2
    std::vector<int> a3 = {1, 2, 3, 4, 5};
    std::vector<int> a4 = {5, 6, 7, 8};
    std::vector<int> e2 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> res2 = ReplaceLastElement(a3, a4);
    assert(res2==e2);

    // Test case 3
    std::vector<int> a5 = {1, 2, 4, 6, 8};
    std::vector<int> a6 = {3, 5, 7, 9};
    std::vector<int> e3 = {1, 2, 4, 6, 3, 5, 7, 9};
    std::vector<int> res3 = ReplaceLastElement(a5, a6);
    assert(res3==e3);
}

int main() {
    testReplaceLastElement();
    return 0;
}