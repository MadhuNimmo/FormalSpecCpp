#include "../FormalSpecCPP-NoSpec/task_id_588.cpp"

#include <cassert>
#include <vector>
#include <algorithm>  // For std::min_element and std::max_element


void test_DifferenceMinMax() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4};
    int out1 = DifferenceMinMax(a1);
    assert(out1 == 3);

    // Test case 2
    std::vector<int> a2 = {4, 5, 12};
    int out2 = DifferenceMinMax(a2);
    assert(out2 == 8);

    // Test case 3
    std::vector<int> a3 = {9, 2, 3};
    int out3 = DifferenceMinMax(a3);
    assert(out3 == 7);
}

int main() {
    test_DifferenceMinMax();
    return 0;
}