#include "task_id_632.cpp"

#include <cassert>
#include <vector>
#include <algorithm>

void testMoveZeroesToEnd() {
    // Test case 1
    std::vector<int> a1 = {1, 0, 2, 0, 3, 4};
    std::vector<int> e1 = {1, 2, 3, 4, 0, 0};
    MoveZeroesToEnd(a1);
    assert(a1 == e1);

    // Test case 2
    std::vector<int> a2 = {2, 3, 2, 0, 0, 4, 0, 5, 0};
    std::vector<int> e2 = {2, 3, 2, 4, 5, 0, 0, 0, 0};
    MoveZeroesToEnd(a2);
    assert(a2 == e2);

    // Test case 3
    std::vector<int> a3 = {0, 1, 0, 1, 1};
    std::vector<int> e3 = {1, 1, 1, 0, 0};
    MoveZeroesToEnd(a3);
    assert(a3 == e3);
}

int main() {
    testMoveZeroesToEnd();
    return 0;
}