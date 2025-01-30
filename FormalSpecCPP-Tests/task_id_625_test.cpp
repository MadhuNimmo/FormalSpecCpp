#include "../FormalSpecCPP/task_id_625.cpp"

#include <cassert>
#include <vector>
#include <algorithm>  // For std::swap

// Assuming the function SwapFirstAndLast is defined as follows:
// void SwapFirstAndLast(std::vector<int>& arr) {
//     if (arr.size() > 1) {
//         std::swap(arr.front(), arr.back());
//     }
// }

// Helper function to compare two vectors
bool arrayEquals(const std::vector<int>& v1, const std::vector<int>& v2) {
    return v1 == v2;
}

void testSwapFirstAndLast() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3};
    std::vector<int> e1 = {3, 2, 1};
    SwapFirstAndLast(a1);
    assert(arrayEquals(a1, e1));

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 4, 4};
    std::vector<int> e2 = {4, 2, 3, 4, 1};
    SwapFirstAndLast(a2);
    assert(arrayEquals(a2, e2));

    // Test case 3
    std::vector<int> a3 = {4, 5, 6};
    std::vector<int> e3 = {6, 5, 4};
    SwapFirstAndLast(a3);
    assert(arrayEquals(a3, e3));
}

int main() {
    testSwapFirstAndLast();
    return 0;
}