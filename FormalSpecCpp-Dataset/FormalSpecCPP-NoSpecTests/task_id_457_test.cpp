#include "../FormalSpecCPP-NoSpec/task_id_457.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testMinLengthSublist() {
    // Test case 1
    std::vector<std::vector<int>> s1 = {{1}, {1, 2}, {1, 2, 3}};
    std::vector<int> e1 = {1};
    std::vector<int> res1 = MinLengthSublist(s1);
    assert(res1 == e1);

    // Test case 2
    std::vector<std::vector<int>> s2 = {{1, 1}, {1, 1, 1}, {1, 2, 7, 8}};
    std::vector<int> e2 = {1, 1};
    std::vector<int> res2 = MinLengthSublist(s2);
    assert(res2 == e2);

    // Test case 3
    std::vector<std::vector<int>> s3 = {{1, 2, 3}, {3, 4}, {11, 12, 14}};
    std::vector<int> e3 = {3, 4};
    std::vector<int> res3 = MinLengthSublist(s3);
    assert(res3 == e3);
}

int main() {
    testMinLengthSublist();
    return 0;
}