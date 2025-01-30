#include "../FormalSpecCPP-NoSpec/task_id_572.cpp"

#include <vector>
#include <cassert>
#include <iostream>

void testRemoveDuplicates() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 2, 3, 4, 5};
    std::vector<int> e1 = {1, 2, 3, 4, 5};
    std::vector<int> res1 = RemoveDuplicates(a1);
    assert(res1==e1);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 2, 4, 5};
    std::vector<int> e2 = {1, 2, 3, 4, 5};
    std::vector<int> res2 = RemoveDuplicates(a2);
    assert(res2==e2);

    // Test case 3
    std::vector<int> a3 = {1, 2, 3, 4, 5};
    std::vector<int> e3 = {1, 2, 3, 4, 5};
    std::vector<int> res3 = RemoveDuplicates(a3);
    assert(res3==e3);
}

int main() {
    testRemoveDuplicates();
    return 0;
}