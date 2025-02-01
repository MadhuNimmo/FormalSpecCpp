#include "task_id_587.cpp"

#include <vector>
#include <cassert>

void testArrayToSeq() {
    // Test case 1
    std::vector<int> a1 = {5, 10, 7, 4, 15, 3};
    std::vector<int> e1 = {5, 10, 7, 4, 15, 3};
    auto res1 = ArrayToSeq(a1);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> a2 = {2, 4, 5, 6, 2, 3, 4, 4, 7};
    std::vector<int> e2 = {2, 4, 5, 6, 2, 3, 4, 4, 7};
    auto res2 = ArrayToSeq(a2);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> a3 = {58, 44, 56};
    std::vector<int> e3 = {58, 44, 56};
    auto res3 = ArrayToSeq(a3);
    assert(res3 == e3);
}

int main() {
    testArrayToSeq();
    return 0;
}