#include "../FormalSpecCPP-NoSpec/task_id_170.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testSumInRange() {
    // Test case 1
    std::vector<int> a1 = {2, 1, 5, 6, 8, 3, 4, 9, 10, 11, 8, 12};
    int out1 = SumInRange(a1, 8, 11);
    assert(out1 == 29);

    // Test case 2
    std::vector<int> a2 = {2, 1, 5, 6, 8, 3, 4, 9, 10, 11, 8, 12};
    int out2 = SumInRange(a2, 5, 8);
    assert(out2 == 16);

    // Test case 3
    std::vector<int> a3 = {2, 1, 5, 6, 8, 3, 4, 9, 10, 11, 8, 12};
    int out3 = SumInRange(a3, 7, 11);
    assert(out3 == 38);
}

int main() {
    testSumInRange();
    return 0;
}