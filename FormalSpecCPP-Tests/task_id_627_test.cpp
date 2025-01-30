#include "../FormalSpecCPP/task_id_627.cpp"

#include <cassert>
#include <vector>

void test_SmallestMissingNumber() {
    // Test case 1
    std::vector<int> a1 = {0, 1, 2, 3};
    int out1 = SmallestMissingNumber(a1);
    assert(out1 == 4);

    // Test case 2
    std::vector<int> a2 = {0, 1, 2, 6, 9};
    int out2 = SmallestMissingNumber(a2);
    assert(out2 == 3);

    // Test case 3
    std::vector<int> a3 = {2, 3, 5, 8, 9};
    int out3 = SmallestMissingNumber(a3);
    assert(out3 == 0);  // Note: Dafny's '-0' is equivalent to '0' in C++
}

int main() {
    test_SmallestMissingNumber();
    return 0;
}