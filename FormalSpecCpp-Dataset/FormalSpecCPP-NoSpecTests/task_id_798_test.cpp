#include "../FormalSpecCPP-NoSpec/task_id_798.cpp"

#include <cassert>  // Required header for assertions
#include <vector>    // Required header for using std::vector

void testArraySum() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3};
    int out1 = ArraySum(a1);
    assert(out1 == 6);

    // Test case 2
    std::vector<int> a2 = {15, 12, 13, 10};
    int out2 = ArraySum(a2);
    assert(out2 == 50);

    // Test case 3
    std::vector<int> a3 = {0, 1, 2};
    int out3 = ArraySum(a3);
    assert(out3 == 3);
}

int main() {
    testArraySum();
    return 0;
}