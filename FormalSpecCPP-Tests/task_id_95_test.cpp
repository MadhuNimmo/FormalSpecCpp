#include "../FormalSpecCPP/task_id_95.cpp"

#include <cassert>
#include <vector>

void testSmallestListLength() {
    // Test case 1
    std::vector<std::vector<int>> s1 = {{1}, {1, 2}};
    int res1 = SmallestListLength(s1);
    assert(res1 == 1);

    // Test case 2
    std::vector<std::vector<int>> s2 = {{1, 2}, {1, 2, 3}, {1, 2, 3, 4}};
    int res2 = SmallestListLength(s2);
    assert(res2 == 2);

    // Test case 3
    std::vector<std::vector<int>> s3 = {{3, 3, 3}, {4, 4, 4, 4}};
    int res3 = SmallestListLength(s3);
    assert(res3 == 3);
}

int main() {
    testSmallestListLength();
    return 0;
}