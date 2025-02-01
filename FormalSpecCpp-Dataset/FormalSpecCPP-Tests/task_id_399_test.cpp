#include "task_id_399.cpp"

#include <cassert>
#include <vector>

void testBitwiseXOR() {
    // Test case 1
    std::vector<int> s1 = {10, 4, 6, 9};
    std::vector<int> s2 = {5, 2, 3, 3};
    std::vector<int> e1 = {15, 6, 5, 10};
    std::vector<int> res1 = BitwiseXOR(s1, s2);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> s3 = {11, 5, 7, 10};
    std::vector<int> s4 = {6, 3, 4, 4};
    std::vector<int> e2 = {13, 6, 3, 14};
    std::vector<int> res2 = BitwiseXOR(s3, s4);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> s5 = {12, 6, 8, 11};
    std::vector<int> s6 = {7, 4, 5, 6};
    std::vector<int> e3 = {11, 2, 13, 13};
    std::vector<int> res3 = BitwiseXOR(s5, s6);
    assert(res3 == e3);
}

int main() {
    testBitwiseXOR();
    return 0;
}