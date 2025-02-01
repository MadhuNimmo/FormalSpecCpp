#include "task_id_623.cpp"

#include <cassert>
#include <vector>

void testPowerOfListElements() {
    // Test case 1
    std::vector<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> e1 = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    std::vector<int> res1 = PowerOfListElements(s1, 2);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> s2 = {10, 20, 30};
    std::vector<int> e2 = {1000, 8000, 27000};
    std::vector<int> res2 = PowerOfListElements(s2, 3);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> s3 = {12, 15};
    std::vector<int> e3 = {248832, 759375};
    std::vector<int> res3 = PowerOfListElements(s3, 5);
    assert(res3 == e3);
}

int main() {
    testPowerOfListElements();
    return 0;
}