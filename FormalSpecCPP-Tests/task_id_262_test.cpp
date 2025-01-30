#include "../FormalSpecCPP/task_id_262.cpp"

#include <cassert>
#include <vector>
#include <utility> // for std::pair

// Assuming SplitArray is defined as:
// std::pair<std::vector<int>, std::vector<int>> SplitArray(const std::vector<int>& array, int index);

void testSplitArray() {
    // Test case 1
    std::vector<int> a1 = {1, 1, 2, 3, 4, 4, 5, 1};
    std::vector<int> expected1 = {1, 1, 2};
    std::vector<int> expected2 = {3, 4, 4, 5, 1};
    auto [res1, res2] = SplitArray(a1, 3);
    assert(res1 == expected1);
    assert(res2 == expected2);

    // Test case 2
    std::vector<int> a2 = {1, 1, 2, 3, 4, 4, 5, 1};
    std::vector<int> expected3 = {1, 1, 2, 3};
    std::vector<int> expected4 = {4, 4, 5, 1};
    auto [res3, res4] = SplitArray(a2, 4);
    assert(res3 == expected3);
    assert(res4 == expected4);

    // Test case 3
    std::vector<int> a3 = {1, 1, 2, 3, 4, 4, 5, 1};
    std::vector<int> expected5 = {1, 1};
    std::vector<int> expected6 = {2, 3, 4, 4, 5, 1};
    auto [res5, res6] = SplitArray(a3, 2);
    assert(res5 == expected5);
    assert(res6 == expected6);
}

int main() {
    testSplitArray();
    return 0;
}