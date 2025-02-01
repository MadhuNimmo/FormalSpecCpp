#include "task_id_603.cpp"

#include <cassert>
#include <vector>
#include <iostream>

void testLucidNumbers() {
    // Test case 1
    std::vector<int> expected1 = {1, 2, 3, 5, 7, 8, 10};
    std::vector<int> result1 = LucidNumbers(10);
    assert(result1 == expected1);

    // Test case 2
    std::vector<int> expected2 = {1, 2, 3, 5, 7, 8, 10, 11, 12, 13, 15, 17, 18, 19, 23, 24};
    std::vector<int> result2 = LucidNumbers(25);
    assert(result2 == expected2);

    // Test case 3
    std::vector<int> expected3 = {1, 2, 3, 5, 7, 8, 10, 11, 12, 13, 15, 17, 18, 19, 23, 24, 26, 28, 29, 30, 31, 36, 37, 39, 41, 42, 43};
    std::vector<int> result3 = LucidNumbers(45);
    assert(result3 == expected3);
}

int main() {
    testLucidNumbers();
    return 0;
}