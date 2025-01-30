#include "../FormalSpecCPP-NoSpec/task_id_62.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

// Assuming the function FindSmallest is defined as follows:
// int FindSmallest(const std::vector<int>& nums);

void testFindSmallest() {
    // Test case 1
    std::vector<int> a1 = {10, 20, 1, 45, 99};
    int out1 = FindSmallest(a1);
    assert(out1 == 1);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3};
    int out2 = FindSmallest(a2);
    assert(out2 == 1);

    // Test case 3
    std::vector<int> a3 = {45, 46, 50, 60};
    int out3 = FindSmallest(a3);
    assert(out3 == 45);
}

int main() {
    testFindSmallest();
    return 0;
}