#include "../FormalSpecCPP/task_id_476.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testSumMinMax() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3};
    int out1 = SumMinMax(a1);
    assert(out1 == 4);

    // Test case 2
    std::vector<int> a2 = {-1, 2, 3, 4};
    int out2 = SumMinMax(a2);
    assert(out2 == 3);  

    // Test case 3
    std::vector<int> a3 = {2, 3, 6};
    int out3 = SumMinMax(a3);
    assert(out3 == 8);  
}

int main() {
    testSumMinMax();
    return 0;
}