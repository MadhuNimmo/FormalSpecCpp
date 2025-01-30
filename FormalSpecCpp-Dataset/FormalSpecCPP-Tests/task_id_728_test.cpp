#include "../FormalSpecCPP/task_id_728.cpp"

#include <cassert>
#include <vector>

void testAddLists() {
    // Test case 1
    std::vector<int> a1 = {10, 20, 30};
    std::vector<int> a2 = {15, 25, 35};
    std::vector<int> e1 = {25, 45, 65};
    std::vector<int> res1 = AddLists(a1, a2);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> a3 = {1, 2, 3};
    std::vector<int> a4 = {5, 6, 7};
    std::vector<int> e2 = {6, 8, 10};
    std::vector<int> res2 = AddLists(a3, a4);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> a5 = {15, 20, 30};
    std::vector<int> a6 = {15, 45, 75};
    std::vector<int> e3 = {30, 65, 105};
    std::vector<int> res3 = AddLists(a5, a6);
    assert(res3 == e3);
}

int main() {
    testAddLists();
    return 0;
}