#include "../FormalSpecCPP-NoSpec/task_id_594.cpp"

#include <cassert>  // Required header for assertions

void testFirstEvenOddDifference() {
    // Test case 1
    std::vector<int> a1 = {1, 3, 5, 7, 4, 1, 6, 8};
    int out1 = FirstEvenOddDifference(a1);
    assert(out1 == 3);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int out2 = FirstEvenOddDifference(a2);
    assert(out2 == 1);

    // Test case 3
    std::vector<int> a3 = {1, 5, 7, 9, 10};
    int out3 = FirstEvenOddDifference(a3);
    assert(out3 == 9);
}

int main() {
    testFirstEvenOddDifference();
    return 0;
}