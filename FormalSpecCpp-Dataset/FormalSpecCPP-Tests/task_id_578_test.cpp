#include "task_id_578.cpp"

#include <vector>
#include <cassert>

void testInterleave() {
    // Test case 1
    std::vector<int> s1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> s2 = {10, 20, 30, 40, 50, 60, 70};
    std::vector<int> s3 = {100, 200, 300, 400, 500, 600, 700};
    std::vector<int> e1 = {1, 10, 100, 2, 20, 200, 3, 30, 300, 4, 40, 400, 5, 50, 500, 6, 60, 600, 7, 70, 700};
    std::vector<int> res1 = Interleave(s1, s2, s3);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> s4 = {10, 20};
    std::vector<int> s5 = {15, 2};
    std::vector<int> s6 = {5, 10};
    std::vector<int> e2 = {10, 15, 5, 20, 2, 10};
    std::vector<int> res2 = Interleave(s4, s5, s6);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> s7 = {11, 44};
    std::vector<int> s8 = {10, 15};
    std::vector<int> s9 = {20, 5};
    std::vector<int> e3 = {11, 10, 20, 44, 15, 5};
    std::vector<int> res3 = Interleave(s7, s8, s9);
    assert(res3 == e3);
}

int main() {
    testInterleave();
    return 0;
}