#include "task_id_751.cpp"

#include <cassert>
#include <vector>

void testIsMinHeap() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5, 6};
    bool res1 = IsMinHeap(a1);
    assert(res1 == true);

    // Test case 2
    std::vector<int> a2 = {2, 3, 4, 5, 10, 15};
    bool res2 = IsMinHeap(a2);
    assert(res2 == true);

    // Test case 3
    std::vector<int> a3 = {2, 10, 4, 5, 3, 15};
    bool res3 = IsMinHeap(a3);
    assert(res3 == false);
}

int main() {
    testIsMinHeap();
    return 0;
}