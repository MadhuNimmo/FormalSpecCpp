#include "task_id_472.cpp"

#include <cassert>
#include <vector>

void testContainsConsecutiveNumbers() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5};
    bool out1 = ContainsConsecutiveNumbers(a1);
    assert(out1 == true);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 5, 6};
    bool out2 = ContainsConsecutiveNumbers(a2);
    assert(out2 == false);

    // Test case 3
    std::vector<int> a3 = {1, 3, 5};
    bool out3 = ContainsConsecutiveNumbers(a3);
    assert(out3 == false);
}

int main() {
    testContainsConsecutiveNumbers();
    return 0;
}