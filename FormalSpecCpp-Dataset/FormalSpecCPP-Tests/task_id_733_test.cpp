#include "task_id_733.cpp"

#include <cassert>
#include <vector>

void testFindFirstOccurrence() {
    // Test case 1
    std::vector<int> a1 = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int out1 = FindFirstOccurrence(a1, 5);
    assert(out1 == 1);

    // Test case 2
    std::vector<int> a2 = {2, 3, 5, 5, 6, 6, 8, 9, 9, 9};
    int out2 = FindFirstOccurrence(a2, 5);
    assert(out2 == 2);

    // Test case 3
    std::vector<int> a3 = {2, 4, 1, 5, 6, 6, 8, 9, 9, 9};
    int out3 = FindFirstOccurrence(a3, 6);
    assert(out3 == 4);
}

int main() {
    testFindFirstOccurrence();
    return 0;
}