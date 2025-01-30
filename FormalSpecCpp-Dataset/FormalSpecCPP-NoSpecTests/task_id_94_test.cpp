#include "../FormalSpecCPP-NoSpec/task_id_94.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testMinSecondValueFirst() {
    // Test case 1
    std::vector<std::vector<int>> s1 = {{1, 3}, {5, 7}, {9, 11}, {13, 15}};
    int res1 = MinSecondValueFirst(s1);
    assert(res1 == 1);

    // Test case 2
    std::vector<std::vector<int>> s2 = {{1, 4}, {5, 1}, {9, 11}, {13, 15}};
    int res2 = MinSecondValueFirst(s2);
    assert(res2 == 5);

    // Test case 3
    std::vector<std::vector<int>> s3 = {{1, 4}, {5, 1}, {9, -1}, {13, 15}};
    int res3 = MinSecondValueFirst(s3);
    assert(res3 == 9);
}

int main() {
    testMinSecondValueFirst();
    return 0;
}