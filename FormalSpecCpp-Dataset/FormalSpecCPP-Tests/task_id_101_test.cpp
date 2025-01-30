#include "../FormalSpecCPP/task_id_101.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

// Assuming the function KthElement is defined as follows:
// int KthElement(const std::vector<int>& arr, int k);

void testKthElement() {
    // Test case 1
    std::vector<int> a1 = {12, 3, 5, 7, 19};
    int out1 = KthElement(a1, 2);
    assert(out1 == 3);

    // Test case 2
    std::vector<int> a2 = {17, 24, 8, 23};
    int out2 = KthElement(a2, 3);
    assert(out2 == 8);

    // Test case 3
    std::vector<int> a3 = {16, 21, 25, 36, 4};
    int out3 = KthElement(a3, 4);
    assert(out3 == 36);
}

int main() {
    testKthElement();
    return 0;
}