#include "task_id_145.cpp"

#include <cassert>
#include <vector>

void test_MaxDifference() {
    // Test case 1
    std::vector<int> a1 = {2, 1, 5, 3};
    int out1 = MaxDifference(a1);
    assert(out1 == 4);

    // Test case 2
    std::vector<int> a2 = {9, 3, 2, 5, 1};
    int out2 = MaxDifference(a2);
    assert(out2 == 8);

    // Test case 3
    std::vector<int> a3 = {3, 2, 1};
    int out3 = MaxDifference(a3);
    assert(out3 == 2);
}

int main() {
    test_MaxDifference();
    return 0;
}