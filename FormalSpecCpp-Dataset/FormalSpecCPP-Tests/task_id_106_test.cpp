#include "task_id_106.cpp"

#include <cassert>
#include <vector>
#include <iostream>

// Assuming the function AppendArrayToSeq and sequenceEquals are defined elsewhere
extern std::vector<int> AppendArrayToSeq(const std::vector<int>& array, const std::vector<int>& seq);
//extern bool sequenceEquals(const std::vector<int>& v1, const std::vector<int>& v2);

void testAppendArrayToSeq() {
    // Test case 1
    std::vector<int> a1 = {5, 6, 7};
    std::vector<int> s1 = {9, 10};
    std::vector<int> e1 = {9, 10, 5, 6, 7};
    std::vector<int> res1 = AppendArrayToSeq(s1, a1);
    assert(res1==e1);

    // Test case 2
    std::vector<int> a2 = {6, 7, 8};
    std::vector<int> s2 = {10, 11};
    std::vector<int> e2 = {10, 11, 6, 7, 8};
    std::vector<int> res2 = AppendArrayToSeq(s2, a2);
    assert(res2==e2);

    // Test case 3
    std::vector<int> a3 = {7, 8, 9};
    std::vector<int> s3 = {11, 12};
    std::vector<int> e3 = {11, 12, 7, 8, 9};
    std::vector<int> res3 = AppendArrayToSeq(s3, a3);
    assert(res3==e3);
}

int main() {
    testAppendArrayToSeq();
    return 0;
}