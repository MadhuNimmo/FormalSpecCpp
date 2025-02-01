#include "task_id_460.cpp"

#include <vector>
#include <cassert>

// Assuming the function GetFirstElements is defined as follows:
// std::vector<int> GetFirstElements(const std::vector<std::vector<int>>& matrix);

void testGetFirstElements() {
    // Test case 1
    std::vector<std::vector<int>> s1 = {{1, 2}, {3, 4, 5}, {6, 7, 8, 9}};
    std::vector<int> e1 = {1, 3, 6};
    std::vector<int> res1 = GetFirstElements(s1);
    assert(res1 == e1);

    // Test case 2
    std::vector<std::vector<int>> s2 = {{1, 2, 3}, {4, 5}};
    std::vector<int> e2 = {1, 4};
    std::vector<int> res2 = GetFirstElements(s2);
    assert(res2 == e2);

    // Test case 3
    std::vector<std::vector<int>> s3 = {{9, 8, 1}, {1, 2}};
    std::vector<int> e3 = {9, 1};
    std::vector<int> res3 = GetFirstElements(s3);
    assert(res3 == e3);
}

int main() {
    testGetFirstElements();
    return 0;
}