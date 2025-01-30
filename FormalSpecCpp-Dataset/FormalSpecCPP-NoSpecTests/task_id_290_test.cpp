#include "../FormalSpecCPP-NoSpec/task_id_290.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testMaxLengthList() {
    // Test case 1
    std::vector<std::vector<int>> s1 = {{0}, {1, 3}, {5, 7}, {9, 11}, {13, 15, 17}};
    std::vector<int> e1 = {13, 15, 17};
    std::vector<int> res1 = MaxLengthList(s1);
    assert(res1==e1);

    // Test case 2
    std::vector<std::vector<int>> s2 = {{1}, {5, 7}, {10, 12, 14, 15}};
    std::vector<int> e2 = {10, 12, 14, 15};
    std::vector<int> res2 = MaxLengthList(s2);
    assert(res2==e2);

    // Test case 3
    std::vector<std::vector<int>> s3 = {{5}, {15, 20, 25}};
    std::vector<int> e3 = {15, 20, 25};
    std::vector<int> res3 = MaxLengthList(s3);
    assert(res3==e3);
}

int main() {
    testMaxLengthList();
    return 0;
}