#include "../FormalSpecCPP-NoSpec/task_id_133.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testSumOfNegatives() {
    // Test case 1
    std::vector<int> a1 = {2, 4, -6, -9, 11, -12, 14, -5, 17};
    int out1 = SumOfNegatives(a1);
    assert(out1 == -32);

    // Test case 2
    std::vector<int> a2 = {10, 15, -14, 13, -18, 12, -20};
    int out2 = SumOfNegatives(a2);
    assert(out2 == -52);

    // Test case 3
    std::vector<int> a3 = {19, -65, 57, 39, 152, -639, 121, 44, 90, -190};
    int out3 = SumOfNegatives(a3);
    assert(out3 == -894);
}

int main() {
    testSumOfNegatives();
    return 0;
}