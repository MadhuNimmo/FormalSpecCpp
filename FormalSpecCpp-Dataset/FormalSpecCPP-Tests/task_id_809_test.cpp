#include "task_id_809.cpp"

#include <cassert>
#include <vector>

void testIsSmaller() {
    // Test case 1
    std::vector<int> s1 = {1, 2, 3};
    std::vector<int> s2 = {2, 3, 4};
    bool res1 = IsSmaller(s1, s2);
    assert(res1 == false);

    // Test case 2
    std::vector<int> s3 = {4, 5, 6};
    std::vector<int> s4 = {3, 4, 5};
    bool res2 = IsSmaller(s3, s4);
    assert(res2 == true);

    // Test case 3
    std::vector<int> s5 = {11, 12, 13};
    std::vector<int> s6 = {10, 11, 12};
    bool res3 = IsSmaller(s5, s6);
    assert(res3 == true);
}

int main() {
    testIsSmaller();
    return 0;
}