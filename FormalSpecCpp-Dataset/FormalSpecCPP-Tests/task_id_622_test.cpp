#include "task_id_622.cpp"

#include <cassert>
#include <vector>

void testFindMedian() {
    // Test case 1
    std::vector<int> a1 = {1, 12, 15, 26, 38};
    std::vector<int> a2 = {2, 13, 17, 30, 45};
    double res1 = FindMedian(a1, a2);
    assert(res1 == 16.0);

    // Test case 2
    std::vector<int> a3 = {2, 4, 8, 9};
    std::vector<int> a4 = {7, 13, 19, 28};
    double res2 = FindMedian(a3, a4);
    assert(res2 == 8.5);

    // Test case 3
    std::vector<int> a5 = {3, 6, 14, 23, 36, 42};
    std::vector<int> a6 = {2, 18, 27, 39, 49, 55};
    double res3 = FindMedian(a5, a6);
    assert(res3 == 25.0);
}

int main() {
    testFindMedian();
    return 0;
}