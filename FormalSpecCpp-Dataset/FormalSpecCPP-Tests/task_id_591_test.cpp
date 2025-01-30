#include "../FormalSpecCPP/task_id_591.cpp"

#include <cassert>
#include <vector>
#include <algorithm>  // For std::swap

void testSwapFirstAndLast() {
    // Test case 1
    std::vector<int> s1 = {12, 35, 9, 56, 24};
    std::vector<int> e1 = {24, 35, 9, 56, 12};
    SwapFirstAndLast(s1);
    assert(s1 == e1);

    // Test case 2
    std::vector<int> s2 = {1, 2, 3};
    std::vector<int> e2 = {3, 2, 1};
    SwapFirstAndLast(s2);
    assert(s2 == e2);

    // Test case 3
    std::vector<int> s3 = {4, 5, 6};
    std::vector<int> e3 = {6, 5, 4};
    SwapFirstAndLast(s3);
    assert(s3 == e3);
}

int main() {
    testSwapFirstAndLast();
    return 0;
}